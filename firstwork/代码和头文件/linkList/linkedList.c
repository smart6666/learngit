#include "../head/linkedList.h"
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	if((*L=(LinkedList)malloc(sizeof(LNode)))==NULL)        /*�����ڴ�ʧ��ʱʧ��ʱ����ERROR*/
        return ERROR;
	(*L)->next=NULL;                                                 /*��ͷ�ڵ���Ϊ��*/
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LNode*psave;
	while(*L)
    {
        psave=(*L)->next;                                    /*������һ���ڵ�ĵ�ַ*/
        free(*L);                                            /*�ͷŵ�ǰ�ڵ�*/
        *L=psave;                                            /*ǰ������һ�ڵ�*/
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(p->next==NULL)                                           /*���ڵ�p������ĩβ��ֱ�ӽ���β����*/
    {
        p->next=q;
        q->next=NULL;
    }
    else                                                        /*���ڵ�p���м����м����*/
    {
        LNode*pt;
        pt=p->next;
        p->next=q;
        q->next=pt;
    }
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode * p, ElemType *e) {
	if(p==NULL||p->next==NULL)                                     /*�����p�����ڻ�p�����һ����㣬�򷵻�ERROR*/
        return ERROR;
    LNode*pt;
	pt=p->next;
	p->next=pt->next;                                              /*��pt�ĺ�̸�ֵ��p�ĺ��*/
	*e=pt->data;                                                   /*��pt�ڵ��е����ݸ�e*/
	free(pt);                                                      /*�ͷ�pt���*/
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode*pt=L->next;                                               /*��������Ŀ�ʼ*/
	while(pt!=NULL)
    {
        (*visit)(pt->data);                                         /*�Ѻ���Ӧ���������е���*/
        pt=pt->next;                                                /*ǰ������һ���ڵ�*/
    }
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LNode*pt=L;
	for(;pt!=NULL;pt=pt->next)                                      /*�������������ԱȽ�����ݺ�e*/
    {
        if(pt->data==e)
        {
            printf("The place of the data is %p\n",pt);             /*���ҵ�����������ڵ��ַ*/
            return SUCCESS;                                          /*�����ط���SUCCESS�����򷵻�ERROR*/
        }
    }
    printf("\nSorry,Can't found\n");
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LNode*pt=(*L)->next;
	if(pt==NULL)
        return ERROR;
    LNode*prev=NULL;
	LNode*next=NULL;
	while(pt!=NULL)
    {
        next=pt->next;                                             /*next������һ��Ҫ����Ľ��ĵ�ַ*/
        pt->next=prev;                                             /*�����ڴ�����ָ��ǰһ������Ľ��*/
        prev=pt;                                                   /*��prevָ�����ڴ���Ľ�㣬Ϊ��һ�δ�����׼��*/
        pt=next;                                                   /*������һ��Ҫ�����Ľ��*/
    }
    (*L)->next=prev;                                               /*ʹͷ�ڵ�ָ���һ�����*/
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if(L==NULL)
        return ERROR;
    LNode *slow=L;                                                  /*������ָ��*/
    LNode *fast=L;                                                  /*���ÿ�ָ��*/
    while(fast&&fast->next)
    {
        slow=slow->next;                                            /*��ָ��ÿ����һ��*/
        fast=fast->next->next;                                      /*��ָ��ÿ��������*/
        if(slow==fast)                                              /*��ָ������˵���л�*/
            return SUCCESS;
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

    LNode*pt=(*L)->next;
    if(pt==NULL&&pt->next==NULL)                                     /*�������Ϊ�ջ�ֻ��һ����㣬�򷵻�ͷ���*/
        return *L;
    LinkedList*pp=&((*L)->next);
    LinkedList a,b;
    while((a=*pp)&&(b=a->next))                                      /*�ж��Ƿ���ż�����*/
    {
        a->next=b->next;
        b->next=a;
        *pp=b;
        pp=&(a->next);
    }

    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode * FindMidNode(LinkedList * L) {

    LNode*pt=(*L)->next;
    if(pt==NULL||pt->next==NULL)                                         /*�������Ϊ�ջ�ֻ��һ����㣬�򷵻�ͷ���*/
        return (*L);
    if(pt->next->next==NULL)                                             /*�������ֻ��������㣬�򷵻ص�һ�����*/
        return pt;
    LNode*q=pt->next->next;                                              /*����������������ϵĽ�㣬��pt��һ����q������*/
        while(q->next&&q->next->next)
        {
            pt=pt->next;
            q=q->next->next;
        }
    return pt->next;
}
