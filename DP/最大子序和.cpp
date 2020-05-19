#include <limits.h>
#include <vector>
using namespace std;

// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 示例:
// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 暴力法
        // int max = INT_MIN, sum;
        // for (int i = 0; i < nums.size(); i++) {
        //     sum = 0;
        //     for (int j = i; j >= 0; --j) {
        //         sum += nums[j];
        //         if (sum > max) {
        //             max = sum;
        //         }
        //     }
        // }
        // return max;
        // 动态规划
        int sum = 0, res = nums[0];
        for (auto& x : nums) {
            sum = max(sum + x, x);
            res = max(sum, res);
        } 
        return res;
    }
};