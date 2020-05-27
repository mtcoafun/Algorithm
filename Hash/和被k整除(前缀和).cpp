#include <unordered_map>
#include <vector>
using namespace std;
// 给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。
// 示例：
// 输入：A = [4,5,0,-2,-3,1], K = 5
// 输出：7
// 解释：
// 有 7 个子数组满足其元素之和可被 K = 5 整除：
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int count = 0, sum = 0;
        for (auto& x : A) {
            sum += x;
            int mod = (sum % K + K) % K;
            if (hash.count(mod)) count += hash[mod];
            ++hash[mod];
        }
        return count;
    }
};