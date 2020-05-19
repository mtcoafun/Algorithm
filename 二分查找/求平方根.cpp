// 实现 int sqrt(int x) 函数。
// 计算并返回 x 的平方根，其中 x 是非负整数。
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
// 示例 1:
// 输入: 4
// 输出: 2
// 示例 2:
// 输入: 8
// 输出: 2
// 说明: 8 的平方根是 2.82842..., 
//      由于返回类型是整数，小数部分将被舍去。
class Solution {
public:
    int mySqrt(int x) {
        // long int res = 1;
        // while (res > 0) {
        //     if (res * res == x) {
        //         return res;
        //         break;
        //     }
        //     if (res * res > x) {
        //         return --res;
        //         break;
        //     }
        //     res++;
        // }
        // return 0;
        long left = 0, right = x, res = 0;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (mid * mid <= x) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return (int)res;
    }
};