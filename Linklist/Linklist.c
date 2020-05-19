#include<ctype.h>
#include<sys/malloc.h> /* malloc()等 */
#include<stdio.h> 
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */
typedef int ElemType;
/*线性表的单链表存储结构 */
struct LNode
 {
   ElemType val;
   struct LNode *next;
 };
typedef struct LNode *LinkList; /* 另一种定义LinkList的方法 */
/* 带有头结点的单链表的基本操作,包括算法2.8,2.9,2.10 */
void InitList(LinkList* L)
{ /* 操作结果：构造一个空的线性表L */
   *L = (LinkList)malloc(sizeof(struct LNode)); /* 产生头结点，并使L指向此头结点 */
   if(!*L) /* 存储分配失败 */
     exit(OVERFLOW);
   (*L)->next=NULL; /* 指针域为空 */
}

void DestroyList(LinkList* L)
{ /* 初始条件：线性表L已存在。操作结果：销毁线性表L */
   LinkList q;
   while(*L)
   {
     q=(*L)->next;
     free(*L);
     *L=q;
   }
}

Status GetElem(LinkList L,int i,ElemType *e) /* 算法2.8 */
{ /* L为带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR */
   int j = 1; /* j为计数器 */
   LinkList p = L->next; /* p指向第一个结点 */
   while(p && j<i) /* 顺指针向后查找，直到p指向第i个元素或p为空 */
   {
     p = p->next;
     j++;
   }
   if(!p || j>i) /* 第i个元素不存在 */
     return ERROR;
   *e = p->val; /* 取第i个元素 */
   return OK;
}


/* 请将下面函数补充完整 */
Status ListInsert(LinkList L,int i,ElemType e) /* 算法2.9。不改变L */
 { /* 在带头结点的单链线性表L中第i个位置之前插入元素e */
    struct LNode* pre;
    struct LNode* s;
     int k = 0;
     pre = L;
     while(pre != NULL && k < i-1) {
         pre = pre->next;
         k++;
     }
     if(!pre) {
         printf("插入位置不合理...");
         return ERROR;
     }
     s = (struct LNode *)malloc(sizeof(struct LNode));
     s->val = e;
     s->next = pre->next;
     pre->next = s;
     return OK;
}

/* 请将下面函数补充完整 */
Status ListDelete(LinkList L,int i,ElemType *e) /* 算法2.10。不改变L */
 { /* 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值 */
     struct LNode *s, *pre;
     int k = 0;
     pre = L;
     while(pre!=NULL&&k < i-1) {
         pre = pre->next;
         k++;
     }
     if(!(pre->next)) {
         printf("删除位置不合理...");
         return ERROR;
     }
     s = pre->next;
     *e = s->val;
     pre->next = s->next;
     free(s);
     return OK;
}

LinkList MergeList(LinkList l1, LinkList l2, LinkList l3) {
    struct LNode *p1, *p2, *p3;
    p1 = l1->next; p2 = l2->next;
    p3 = l3;
    while (p1&&p2) {
        if (p1->val >= p2->val) {
            struct LNode *s; s = (struct LNode *)malloc(sizeof(struct LNode));
            s->val = p1->val;
            p3->next = s;
            p3 = p3->next;
            p1 = p1->next;
        }
        else {
            struct LNode *s; s = (struct LNode *)malloc(sizeof(struct LNode));
            s->val = p2->val;
            p3->next = s;
            p3 = p3->next;
            p2 = p2->next;
        }
    }
    struct LNode *t = p1 ? p1 : p2;
    return l3->next;
}


void ListTraverse(LinkList L)
{
   LinkList p=L->next;
   while(p)
   {
     printf("%3d",p->val);
     p=p->next;
   }
   printf("\n");
}

int main()
 {
	LinkList L; 
	ElemType e;
	Status i;
	int j;
	InitList(&L);
	for(j=1;j<=5;j++)
		i=ListInsert(L,1,j);
	printf("在L的表头依次插入1～5后：L=");
	ListTraverse(L); /* 依次对元素调用print()，输出元素的值 */
	
	GetElem(L,4,&e);
	printf("第5个元素的值为：%d\n",e);
	
	i=ListDelete(L,4,&e); /* 删除第4个数据 */
	if(i==ERROR)
		printf("删除元素失败\n");
	else
		printf("删除元素成功，其值为：%d\n",e);
	
	printf("依次输出L的元素：");
	ListTraverse(L);
	
	DestroyList(&L);
}
