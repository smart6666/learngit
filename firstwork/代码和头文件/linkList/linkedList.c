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
	if((*L=(LinkedList)malloc(sizeof(LNode)))==NULL)        /*创建内存失败时失败时返回ERROR*/
        return ERROR;
	(*L)->next=NULL;                                                 /*将头节点设为空*/
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
        psave=(*L)->next;                                    /*保存下一个节点的地址*/
        free(*L);                                            /*释放当前节点*/
        *L=psave;                                            /*前进至下一节点*/
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
	if(p->next==NULL)                                           /*若节点p在链表末尾则直接进行尾插入*/
    {
        p->next=q;
        q->next=NULL;
    }
    else                                                        /*若节点p在中间则中间插入*/
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
	if(p==NULL||p->next==NULL)                                     /*若结点p不存在或p是最后一个结点，则返回ERROR*/
        return ERROR;
    LNode*pt;
	pt=p->next;
	p->next=pt->next;                                              /*将pt的后继赋值给p的后继*/
	*e=pt->data;                                                   /*将pt节点中的数据给e*/
	free(pt);                                                      /*释放pt结点*/
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
	LNode*pt=L->next;                                               /*设置链表的开始*/
	while(pt!=NULL)
    {
        (*visit)(pt->data);                                         /*把函数应用于链表中的项*/
        pt=pt->next;                                                /*前进至下一个节点*/
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
	for(;pt!=NULL;pt=pt->next)                                      /*遍历整个链表，对比结点数据和e*/
    {
        if(pt->data==e)
        {
            printf("The place of the data is %p\n",pt);             /*若找到，则输出给节点地址*/
            return SUCCESS;                                          /*并返回返回SUCCESS，否则返回ERROR*/
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
        next=pt->next;                                             /*next保存下一个要处理的结点的地址*/
        pt->next=prev;                                             /*将正在处理结点指向前一个处理的结点*/
        prev=pt;                                                   /*是prev指向正在处理的结点，为下一次处理做准备*/
        pt=next;                                                   /*进入下一个要操作的结点*/
    }
    (*L)->next=prev;                                               /*使头节点指向第一个结点*/
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
    LNode *slow=L;                                                  /*设置慢指针*/
    LNode *fast=L;                                                  /*设置快指针*/
    while(fast&&fast->next)
    {
        slow=slow->next;                                            /*慢指针每次走一步*/
        fast=fast->next->next;                                      /*快指针每次走两步*/
        if(slow==fast)                                              /*两指针相遇说明有环*/
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
    if(pt==NULL&&pt->next==NULL)                                     /*如果链表为空或只有一个结点，则返回头结点*/
        return *L;
    LinkedList*pp=&((*L)->next);
    LinkedList a,b;
    while((a=*pp)&&(b=a->next))                                      /*判断是否有偶数结点*/
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
    if(pt==NULL||pt->next==NULL)                                         /*如果链表为空或只有一个结点，则返回头结点*/
        return (*L);
    if(pt->next->next==NULL)                                             /*如果链表只有两个结点，则返回第一个结点*/
        return pt;
    LNode*q=pt->next->next;                                              /*如果链表有两个以上的结点，则pt走一步，q走两步*/
        while(q->next&&q->next->next)
        {
            pt=pt->next;
            q=q->next->next;
        }
    return pt->next;
}
