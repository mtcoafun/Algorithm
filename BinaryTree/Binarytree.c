#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define false 0;
#define true 1;
struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

/*给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
示例 1:
输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]
输出: true
示例 2:
输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]
输出: false*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL) { return true; }
    else if ((p != NULL && q == NULL) || (q != NULL && p == NULL)) {
        return false;
    }
    if (p->val == q->val) {
        if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
            return true;
        }
    }
    return false;
}

/*给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3*/
bool mirror (struct TreeNode* n1, struct TreeNode* n2) {
    if (n1 == NULL && n2 == NULL) { return true; }
    else if (n1 == NULL || n2 == NULL) return false;
    if (n1->val == n2->val) {
        if (mirror(n1->left, n2->right) && mirror(n1->right,n2->left)) {
            return true;
        }
    }
    return false;
}
bool isSymmetric(struct TreeNode* root){
    return mirror(root, root);
}