#include <cmath>
#include <queue>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 深度优先搜索法
        // int dep = 0, ldep, rdep;
        // if (root == nullptr) dep = 0;
        // else {
        //     ldep = maxDepth(root->left);
        //     rdep = maxDepth(root->right);
        //     if (ldep > rdep) {
        //         dep = ldep + 1;
        //     }
        //     else dep = rdep + 1;
        // }
        // return dep;
        if (root == nullptr) return 0;
        return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
        // 广度优先搜索法（使用队列）
        int deep = 0;
        if (!root) return 0;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            for (int i = bfs.size(); i > 0; --i) {
                TreeNode* temp = bfs.front();
                bfs.pop();
                if (temp->left) bfs.push(temp->left);
                if (temp->right) bfs.push(temp->right);
            }
            ++deep;
        } 
        return deep;
    }
};