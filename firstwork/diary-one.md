# QG训练营移动组第一周周记：2019年3月24日

## 3/23周六
    今天完成了大组布置的作业，单向链表和双向链表，之前一直
    都是看代码的，今天自己写代码，才知道完成一个像样的链表
    那么费时间的。虽然写得很烦，但写好后真的很开心，感觉编
    程超有趣。
##### 下面是我的学习总结：
1、用双重指针的方法倒置偶数结点：
```
    LNode* ReverseEvenList(LinkedList *L) {

    LNode*pt=(*L)->next;
    if(pt==NULL&&pt->next==NULL)       /*如果链表为空或只有一个结点，则返回头结点*/
        return *L;
    LinkedList*pp=&((*L)->next);
    LinkedList a,b;
    while((a=*pp)&&(b=a->next))        /*判断是否有偶数结点*/
    {
        a->next=b->next;
        b->next=a;
        *pp=b;
        pp=&(a->next);
    }

    return *L;
}
```
    通过取结点指针域的指针的地址，可以方便的决定其指向

2、通过两个指针寻找链表的中点：
```
LNode * FindMidNode(LinkedList * L) {

    LNode*pt=(*L)->next;
    if(pt==NULL||pt->next==NULL)     /*如果链表为空或只有一个结点，则返回头结点*/
        return (*L);
    if(pt->next->next==NULL)         /*如果链表只有两个结点，则返回第一个结点*/
        return pt;
    LNode*q=pt->next->next;          /*如果链表有两个以上的结点，则pt走一步，q走两步*/
        while(q->next&&q->next->next)
        {
            pt=pt->next;
            q=q->next->next;
        }
    return pt->next;
}
```
    设置两个指针，一个一次走两步，一个一次走一步，当快的走到终点时，
    慢的就正好走到了中点
---
## 3/24周日
    今天一觉醒来，睁开双眼，突然想到：天呐，就得交作业了，不知道师兄凶不
    凶，严不严，我得快点完成了，不然会gg的。天呐，我还不知道怎么用GitHub
    交作业，怎么办，怎么办，对了，看廖雪峰的git教程，学了一个早上终于明应
    该怎么做了，真的有点佩服自己了，哈哈。
##### 想想今天学到了什么：
1、学了很多git的基本命令和他的一些内部原理,下面是一点总结：
    
    git branch 查看本地所有分支
    git status 查看当前状态
    git commit 提交
    git branch -a 查看所有的分支
    git branch -r 查看远程所有分支
    git commit -am "XXX" 提交并且加注释
    git push origin master 将文件给推到服务器上
    git remote show origin 显示远程库origin里的资源
2、我在网上看了如何使用markdown写了这篇周记，有点简陋，希望严格的师兄可以网开一面~~~
***

## 一周总结：
- 古人学问无遗力，少壮工夫老始成。

- 纸上得来终觉浅，绝知此事要躬行。



