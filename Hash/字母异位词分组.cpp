#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
// 示例:
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hash;
        int index = 0;
        for (auto e : strs) {
            string org = e;
            sort(org.begin(), org.end());
            if (hash.count(org) <= 0) hash[org] = index++;
        }
        vector<vector<string> > res (index, vector<string>());
        for (auto e : strs) {
            string cur = e;
            sort(cur.begin(), cur.end());
            res[hash[cur]].push_back(e);
        }
        return res;
    }
};
