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
typedef int SElemType; /* 定义栈元素类型，此句要在c3-1.h的前面 */
/* 栈的顺序存储表示 */
 typedef struct SNode
 {
   SElemType data; 
   struct SNode *next;
 }SNode, *LinkStack; /* 顺序栈 */

void InitStack(LinkStack* top)  { /* 构造一个空栈S */  
	*top = (LinkStack )malloc(sizeof(SNode));  
	if (!*top) {  
	    printf(" 内存分配失败! \n");  
	    exit(OVERFLOW);  
	}  
	(*top)->next = NULL;  
}  

void ClearStack(LinkStack *top) {
    (*top)->next = NULL;
}

void DestroyStack(LinkStack *top)  
 { /* 销毁栈S，S不再存在 */  
	SNode *t;  
	while(*top)  
	{  
	    t = (*top)->next;  
	    free(*top);  
	    *top = t;  
	}  
}  

Status StackEmpty(LinkStack top)  
{ /* 若栈S为空栈，则返回TRUE，否则返回FALSE */  
if(top->next == NULL)  
	return TRUE;  
else  
	return FALSE;  
}  

int StackLength(LinkStack top)  
{ /* 返回S的元素个数，即栈的长度 */  
	int j = 0;  
	LinkStack t;  
	t = top->next;  
	while (t!=NULL) {  
		t = t->next;  
		j++;  
	}  
	return j;  
}  

Status GetTop(LinkStack top,SElemType *e)  
{ /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */  
	if (top->next == NULL) {  
		printf(" 空栈无法获取栈顶 \n");  
		return ERROR;  
	}  
	*e = top->next->data;
	return *e;  
}  

void Push(LinkStack top, SElemType e)  
{ /* 插入元素e为新的栈顶元素 */  
	SNode * temp;  
	temp=(SNode * )malloc(sizeof(SNode));  
	if(temp == NULL) {  
		printf(" 申请空间失败! \n");  
		exit(OVERFLOW);  
	}/* 申请空间失败 */  
	temp->data=e;  
	temp->next=top->next;  
	top->next=temp; /* 修改当前栈顶指针 */  
}  

Status Pop(LinkStack top,SElemType *e)  
{ /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */  
	SNode * temp;  
	temp = top->next;  
	if(temp == NULL) {  
		printf(" 栈已为空，无法继续弹出 ");  
		return FALSE;  
	} /*栈为空*/  
	top->next=temp->next;  
	*e=temp->data;  
	free(temp); /* 释放存储空间 */  
	return TRUE;  
}  

void StackTraverse(LinkStack top)  
{   
	LinkStack t;  
	t = top->next;  
	while (t) {  
		printf(" %3d", t->data);  
		t = t->next;  
	}  
	printf("\n");  
}  

int main()  
{  
int j;  
LinkStack s;  
SElemType e;  
InitStack(&s);  
for(j=1;j<=12;j++)  
	Push(s,j);  
printf(" 栈中元素依次为：");  
StackTraverse(s);  
Pop(s,&e);  
printf(" 弹出的栈顶元素 e = %d\n",e);  
Pop(s,&e);  
printf(" 弹出的栈顶元素 e = %d\n",e);  
printf(" 栈空否：%d (1:空 0:否)\n",StackEmpty(s));  
GetTop(s,&e);  
printf(" 栈顶元素 e = %d 栈的长度为 %d\n",e,StackLength(s));  
StackTraverse(s);  
ClearStack(&s);  
printf(" 清空栈后，栈空否：%d (1:空 0:否)\n",StackEmpty(s));  
//判断回文数  
DestroyStack(&s);  
printf(" 栈已销毁\n");  
//isPalindromeNum(111222111);  
return 0;  
}  

