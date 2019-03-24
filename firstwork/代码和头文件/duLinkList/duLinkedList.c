#include "../head/duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	if((*L=(DuLinkedList)malloc(sizeof(DuLNode)))==NULL)         /*�����ڴ�ʧ��ʱʧ��ʱ����ERROR*/
        return ERROR;
	(*L)->next=(*L)->prior=NULL;                                 /*��ͷ�ڵ���Ϊ��*/
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode*psave;
	while(*L)
    {
        psave=(*L)->next;                                        /*������һ���ڵ�ĵ�ַ*/
        free(*L);                                                /*�ͷŵ�ǰ�ڵ�*/
        *L=psave;                                                /*ǰ������һ�ڵ�*/
    }
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL)
        return ERROR;
    else
    {
        q->next=p;
        q->prior=p->prior;
        p->prior->next=q;
        p->prior=q;
    }
    return SUCCESS;

}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL)
        return ERROR;
    else if(p->next==NULL)
    {
        q->prior=p;
        q->next=p->next;
        p->next=q;
    }
    else
    {
        q->prior=p;                                     /*��p��ֵ��q��ǰ�� */
        q->next=p->next;                                /*��p->next��ֵ��s�ĺ��*/
        p->next->prior=q;                               /*��q��ֵ��p->next��ǰ��*/
        p->next=q;                                      /*��q��ֵ��p�ĺ��*/
    }
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(p==NULL||p->next==NULL)
        return ERROR;
    DuLNode*pt;
	pt=p->next;
	pt->prior->next=pt->next;                              /*��pt->next��ֵ��pt->prior�ĺ��*/
	pt->next->prior=pt->prior;                             /*��pt->prior��ֵ��p->next��ǰ��*/
	*e=pt->data;
	free(pt);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode*pt=L->next;                                     /*��������Ŀ�ʼ*/
	while(pt!=NULL)
    {
        (*visit)(pt->data);                                 /*�Ѻ���Ӧ���������е���*/
        pt=pt->next;                                        /*ǰ������һ���ڵ�*/
    }
}

