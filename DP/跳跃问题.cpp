#include <vector>
#include <unordered_set>
using namespace std;

// 给定一个非负整数数组，你最初位于数组的第一个位置。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
// 示例:
// 输入: [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
//      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
class Solution {
public:
    int jump(vector<int>& nums) {
        int times = 0, mostFar = 0, end = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            if (mostFar >= i) {
                mostFar = max(mostFar, i + nums[i]);
                if (end == i) {
                    end = mostFar;
                    ++times;
                }
            }
        }
        return times;
    }
};

// 给定一个非负整数数组，你最初位于数组的第一个位置。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 判断你是否能够到达最后一个位置。
// 示例 1:
// 输入: [2,3,1,1,4]
// 输出: true
// 解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
// 示例 2:
// 输入: [3,2,1,0,4]
// 输出: false
// 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int mostFar = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > mostFar) {
                return false;
            }
            mostFar = max(mostFar, i + nums[i]);
        }
        return true;
    }
};