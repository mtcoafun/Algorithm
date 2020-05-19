// 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
// 示例 1:
// 输入: 2.00000, 10
// 输出: 1024.00000
// 示例 2:
// 输入: 2.10000, 3
// 输出: 9.26100
// 示例 3:
// 输入: 2.00000, -2
// 输出: 0.25000
// 解释: 2-2 = 1/22 = 1/4 = 0.25
// 递归算法
class Solution {
public:
    double helper(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        double ans = helper(x, n / 2);
        return n % 2 ? ans * ans * x : ans * ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        if (N == 0) return 1;
        return N < 0 ? 1 / helper(x, -N) : helper(x, N);
    }
};