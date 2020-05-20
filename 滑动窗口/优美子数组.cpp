#include <vector>
using namespace std;
// 给你一个整数数组 nums 和一个整数 k。
// 如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」
// 请返回这个数组中「优美子数组」的数目。

// 示例 1：
// 输入：nums = [1,1,2,1,1], k = 3
// 输出：2
// 解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
// 示例 2：
// 输入：nums = [2,4,6], k = 1
// 输出：0
// 解释：数列中不包含任何奇数，所以不存在优美子数组。
// 示例 3：
// 输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
// 输出：16
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // long int num = 0, snum = 0;
        // if (nums.size() == 0 || nums.size() > 50000 || k > nums.size() || k < 1) return 0;
        // for (long int i = 0; i < (long int)nums.size(); i++) {
        //     //if (nums[i] > 10000) throw "error";
        //     long int j = i;
        //     while (j < nums.size() && snum <= k) {
        //         if (nums[j] % 2 == 1) snum++;
        //         if (snum == k) num++;
        //         j++;
        //     }
        //     snum = 0;
        // }
        // return num;

        // int n = (int)nums.size();
        // int odd[n + 2], ans = 0, cnt = 0;
        // for (int i = 0; i < n; ++i) {
        //     if (nums[i] & 1) odd[++cnt] = i;
        // }
        // odd[0] = -1, odd[++cnt] = n;
        // for (int i = 1; i + k <= cnt; ++i) {
        //     ans += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]); 
        // }
        // return ans;

        vector<int> cnt;
        int n = (int)nums.size();
        cnt.resize(n + 1, 0);
        int odd = 0, ans = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; ++i) {
            odd += nums[i] & 1;
            ans += odd >= k ? cnt[odd - k] : 0;
            cnt[odd] += 1;
        }
        return ans;
    }
};