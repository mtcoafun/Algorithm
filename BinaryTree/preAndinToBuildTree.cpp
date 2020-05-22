#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    unordered_map<int, int> inhash;
    // 递归函数法
    TreeNode* getTree(const vector<int>& preorder, const vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
        if (preLeft > preRight) return nullptr;
        int preorderRoot = preLeft;
        int inorderRoot = inhash[preorder[preorderRoot]];
        TreeNode* root = new TreeNode(preorder[preorderRoot]);
        int sizeOfSubleft = inorderRoot - inLeft;
        root->left = getTree(preorder, inorder, preLeft + 1, preLeft + sizeOfSubleft, inLeft, inorderRoot - 1);
        root->right = getTree(preorder, inorder, preLeft + sizeOfSubleft + 1, preRight, inorderRoot + 1, inRight);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preLen = preorder.size(), inLen = inorder.size();
        for (int i = 0; i < inorder.size(); i++) {
            inhash[inorder[i]] = i;
        }
        return getTree(preorder, inorder, 0, preLen - 1, 0, inLen - 1);
    }
};