#include <vector>
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
    vector<vector<int> > res;
    void bfs(TreeNode* root) {
        if (!root) return ;
        queue<TreeNode*> bfsq;
        bfsq.push(root);
        while (!bfsq.empty()) {
            res.push_back(vector<int> ());
            for(int i = bfsq.size(); i > 0; i--) {
                TreeNode* temp = bfsq.front();
                res.back().push_back(temp->val);
                bfsq.pop();
                if (temp->left) bfsq.push(temp->left);
                if (temp->right) bfsq.push(temp->right);
            }
        }
    }
    vector<vector<int> > levelOrder(TreeNode* root) {
        bfs(root);
        return res;
    }
};