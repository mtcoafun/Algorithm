#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
// 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
// 两棵树重复是指它们具有相同的结构以及相同的结点值。
// 示例 1：
//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
// 下面是两个重复的子树：
//       2
//      /
//     4
// 和
//     4
// 因此，你需要以列表的形式返回上述重复子树的根结点。
class Solution {
public:
    string dfs(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& map) {
        if (root == 0) return "";
        string str = to_string(root->val) + dfs(root->left, res, map) + dfs(root->right, res, map);
        if (map[str] == 1) res.push_back(root);
        map[str]++;
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> map;
        dfs(root, res, map);
        return res;
    }
};