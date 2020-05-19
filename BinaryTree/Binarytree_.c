#include<ctype.h>
#include<sys/malloc.h> /* malloc()等 */
#include<stdio.h> 
#include<stdlib.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
//#define OVERFLOW -2
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */
typedef char TElemType;
char Nil = '#'; /* 字符型以空格符为空 */
int max(int a, int b) {
  return a > b ? a : b;
}
/*二叉树的二叉链表存储表示 */
typedef struct BiTNode
{
   TElemType data;
   struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
}BiTNode, *BiTree;

void InitBiTree(BiTree *T)
{ /* 操作结果：构造空二叉树T */
   *T=NULL;
}

void CreateBiTree(BiTree *T)
 { /* 按先序次序输入二叉树中结点的值(可为字符型或整型，在主程中定义)，*/
   /* 构造二叉链表表示的二叉树T。变量Nil表示空(子)树。有改动 */
   //完成本函数
   char ch;
   scanf("%c", &ch);
   if (ch == Nil) {
     *T = NULL;
     return ;
   }
   else {
     *T = (BiTree)malloc(sizeof(BiTNode));
     if (!(*T)) {
       printf(" 内存分配失败\n");
       exit(OVERFLOW);
     }
     (*T)->data = ch;
     CreateBiTree(&((*T)->lchild));
     CreateBiTree(&((*T)->rchild));
   }
   return ;
 }

void DestroyBiTree(BiTree *T)
 { /* 初始条件：二叉树T存在。操作结果：销毁二叉树T */
   if(*T) /* 非空树 */
   {
     if((*T)->lchild) /* 有左孩子 */
       DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
     if((*T)->rchild) /* 有右孩子 */
       DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
     free(*T); /* 释放根结点 */
     *T=NULL; /* 空指针赋0 */
   }
 }

// 计算二叉树的深度
int maxDepth(BiTNode* root) {
  int deep = 0;
  if (root == NULL) return 0;
  return max(maxDepth(root->lchild), maxDepth(root->rchild)) + 1;
}

// 计算叶子结点的个数
static int nums = 0;
int numsOfChild(BiTNode* root) {
  if (!root) return 0;
  if (root != NULL) {
    if (root->lchild == NULL && root->rchild == NULL) ++nums;
    numsOfChild(root->lchild);
    numsOfChild(root->rchild);
  }
  return nums;
}

//拷贝二叉树
void copyTree(BiTNode* root, BiTNode* copy) {
  if (root) {
    copy = (BiTNode *)malloc(sizeof(BiTNode));
    copy->data = root->data;
    copyTree(root->lchild, copy->lchild);
    copyTree(root->rchild, root->rchild);
  }
  else copy = NULL;
}

void PreOrderTraverse(BiTree T,void(*Visit)(TElemType))
 { /* 初始条件：二叉树T存在，Visit是对结点操作的应用函数。算法6.1，有改动 */
   /* 操作结果：先序递归遍历T，对每个结点调用函数Visit一次且仅一次 */
   if(T) /* T不空 */
   {
     Visit(T->data); /* 先访问根结点 */
     PreOrderTraverse(T->lchild, Visit); /* 再先序遍历左子树 */
     PreOrderTraverse(T->rchild, Visit); /* 最后先序遍历右子树 */
   }
 }

 void InOrderTraverse(BiTree T,void(*Visit)(TElemType))
 { /* 初始条件：二叉树T存在，Visit是对结点操作的应用函数 */
   /* 操作结果：中序递归遍历T，对每个结点调用函数Visit一次且仅一次 */
   if(T)
   {
     InOrderTraverse(T->lchild,Visit); /* 先中序遍历左子树 */
     Visit(T->data); /* 再访问根结点 */
     InOrderTraverse(T->rchild,Visit); /* 最后中序遍历右子树 */
   }
 }

 void PostOrderTraverse(BiTree T,void(*Visit)(TElemType))
 { /* 初始条件：二叉树T存在，Visit是对结点操作的应用函数 */
   /* 操作结果：后序递归遍历T，对每个结点调用函数Visit一次且仅一次 */
   if(T) /* T不空 */
   {
     PostOrderTraverse(T->lchild,Visit); /* 先后序遍历左子树 */
     PostOrderTraverse(T->rchild,Visit); /* 再后序遍历右子树 */
     Visit(T->data); /* 最后访问根结点 */
   }
 }

Status BiTreeEmpty(BiTree T)
 { /* 初始条件：二叉树T存在。操作结果：若T为空二叉树，则返回TRUE，否则FALSE */
   if(T)
     return FALSE;
   else
     return TRUE;
 }
 TElemType Root(BiTree T)
 {  //初始条件：二叉树T存在。操作结果：返回T的根
   if(BiTreeEmpty(T))
     return Nil;
   else
     return T->data;
 }
 
void visitT(TElemType e)
 {
   printf("%c ",e);
 }

int main()
{
   BiTree T;
   TElemType e1;
   InitBiTree(&T);
   printf("构造空二叉树后,树空否？%d(1:是 0:否)\n",BiTreeEmpty(T));
   e1 = Root(T);
   if(e1 != Nil)
     printf("二叉树的根为: %c\n",e1);
   else
     printf("树空，无根\n");
   printf("请先序输入二叉树(如:ab三个 # 表示a为根结点,b为左子树的二叉树)\n");
   CreateBiTree(&T);
   printf("建立二叉树后,树空否？%d(1:是 0:否) \n",BiTreeEmpty(T));
   e1 = Root(T);
   if(e1!=Nil)
     printf("二叉树的根为: %c",e1);
   else
     printf("树空，无根");
   printf("\n二叉树的深度为: %d", maxDepth(T));
   printf("\n二叉树的叶子结点个数为: %d", numsOfChild(T));
   BiTNode copy;
   printf("\n拷贝二叉树");
   copyTree(T, &copy);
   printf("\n先序递归遍历拷贝后的树:");
   PreOrderTraverse(&copy, visitT);
   printf("\n先序递归遍历二叉树:");
   PreOrderTraverse(T,visitT);
   printf("\n中序递归遍历二叉树:");
   InOrderTraverse(T,visitT);
   printf("\n后序递归遍历二叉树:");
   PostOrderTraverse(T,visitT);
   DestroyBiTree(&T);
 }
