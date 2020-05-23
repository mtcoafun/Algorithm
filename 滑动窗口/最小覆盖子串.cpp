#include <string>
#include <unordered_map>
using namespace std;

// 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
// 示例：
// 输入: S = "ADOBECODEBANC", T = "ABC"
// 输出: "BANC"
// 说明：
// 如果 S 中不存这样的子串，则返回空字符串 ""。
// 如果 S 中存在这样的子串，我们保证它是唯一的答案。
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (auto& c : t) {
            need[c]++;
        }
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT32_MAX;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (need[d] == window[d]) valid--;
                    window[d]--;
                }
            }
        }
        return len == INT32_MAX ? "" : s.substr(start, len);
    }
};


