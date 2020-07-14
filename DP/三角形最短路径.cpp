#include <vector>
using namespace std;
// 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
// 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
// 例如，给定三角形：
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
// 说明：
// 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

class Solution {
public:
    vector<vector<int> > memo;
    int dp(vector<vector<int> >& triangle, int row, int col) {
        if (row == triangle.size() - 1) return triangle[row][col];
        if (memo[row][col] == 0) {
            memo[row][col] = triangle[row][col] + min(dp(triangle, row + 1, col), dp(triangle, row + 1, col + 1));
        }
        return memo[row][col];
    }
    int minimumTotal(vector<vector<int> >& triangle) {
        // memo = vector(triangle.size(), vector(triangle.size(), 0));
        // return dp(triangle, 0, 0);

        // 由下至上动态规划
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
