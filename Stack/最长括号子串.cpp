#include <string>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;

// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
// 示例 1:
// 输入: "(()"
// 输出: 2
// 解释: 最长有效括号子串为 "()"
// 示例 2:
// 输入: ")()())"
// 输出: 4
// 解释: 最长有效括号子串为 "()()"
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case '(':
                st.push(i);
                break;
            case ')':
                st.pop();
                if (st.empty()) st.push(i);
                else ans = max(ans, i - st.top());
                break;
            }
        }
        return ans;
    }
};