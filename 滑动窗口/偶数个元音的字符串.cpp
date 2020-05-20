#include <vector>
#include <string>
using namespace std;

// 给你一个字符串 s ，
// 请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。
// 示例 1：
// 输入：s = "eleetminicoworoep"
// 输出：13
// 解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。
// 示例 2：
// 输入：s = "leetcodeisgreat"
// 输出：5
// 解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。
// 示例 3：
// 输入：s = "bcbcbc"
// 输出：6
// 解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。
class Solution {
public:
    int findTheLongestSubstring(string s) {
        // 每一个原音占据一个比特位00000 = uoiea，0代表出现偶数次，1代表出现奇数次
        // 当碰到该原音时，和自己的那位亦或，这也是左移的原因
        int len = 0, status = 0;
        vector<int> postion (32, -1); postion[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case 'a' :
                    status = status ^ (1 << 0);
                    break;
                case 'e' :
                    status = status ^ (1 << 1);
                    break;
                case 'i' :
                    status = status ^ (1 << 2);
                    break;
                case 'o' :
                    status = status ^ (1 << 3);
                    break;
                case 'u' :
                    status = status ^ (1 << 4);
                    break;
            }
            if (postion[status] != -1) len = max(len, i + 1 - postion[status]);
            else postion[status] = i + 1;
        }
        return len;
    }
};