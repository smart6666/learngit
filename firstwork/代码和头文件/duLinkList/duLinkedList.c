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
	if((*L=(DuLinkedList)malloc(sizeof(DuLNode)))==NULL)         /*创建内存失败时失败时返回ERROR*/
        return ERROR;
	(*L)->next=(*L)->prior=NULL;                                 /*将头节点设为空*/
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
        psave=(*L)->next;                                        /*保存下一个节点的地址*/
        free(*L);                                                /*释放当前节点*/
        *L=psave;                                                /*前进至下一节点*/
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
        q->prior=p;                                     /*把p赋值给q的前驱 */
        q->next=p->next;                                /*把p->next赋值给s的后继*/
        p->next->prior=q;                               /*把q赋值给p->next的前驱*/
        p->next=q;                                      /*把q赋值给p的后继*/
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
	pt->prior->next=pt->next;                              /*把pt->next赋值给pt->prior的后继*/
	pt->next->prior=pt->prior;                             /*把pt->prior赋值给p->next的前驱*/
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
	DuLNode*pt=L->next;                                     /*设置链表的开始*/
	while(pt!=NULL)
    {
        (*visit)(pt->data);                                 /*把函数应用于链表中的项*/
        pt=pt->next;                                        /*前进至下一个节点*/
    }
}

