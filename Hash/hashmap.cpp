#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
// 示例:
// 给定 nums = [2, 7, 11, 15], target = 9
// 因为 nums[0] + nums[1] = 2 + 7 = 9
// 所以返回 [0, 1]*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            if (hash.count(temp) > 0) {
                res.push_back(hash[temp]);
                res.push_back(i);
                return res;
            }
            hash.insert(make_pair(nums[i], i));
        }
        throw " numbers do not exist. ";
    }
};

// 给定两个字符串 s 和 t，判断它们是否是同构的。
// 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
// 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
// 示例 1:
// 输入: s = "egg", t = "add"
// 输出: true
// 示例 2:
// 输入: s = "foo", t = "bar"
// 输出: false
// 示例 3:
// 输入: s = "paper", t = "title"
// 输出: true
// 说明:
// 你可以假设 s 和 t 具有相同的长度。
class Solution1 {
public:
    bool ifOrNot(string s, string t) {
        unordered_map<char, char> map;
        for (int i = 0; i < s.size(); i++) {
            if (map.count(s[i]) > 0) {
                if (map[s[i]] != t[i]) return false;
            }
            else map[s[i]] = t[i];
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return ifOrNot(s, t) && ifOrNot(t, s);
    }
};

// 假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
// 你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。
// 示例 1:
// 输入:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
// 输出: ["Shogun"]
// 解释: 他们唯一共同喜爱的餐厅是“Shogun”。
// 示例 2:
// 输入:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["KFC", "Shogun", "Burger King"]
// 输出: ["Shogun"]
// 解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
class Solution2 {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map2;
        vector<string> res;
        int min = list1.size() + list2.size() - 2;
        for (int i = 0; i < list2.size(); i++) {
            map2[list2[i]] = i;
        }
        for (auto key = 0; key < list1.size(); key++) {
            if (map2.count(list1[key]) > 0) {
                if (min >= key + map2[list1[key]]) {
                    res.push_back(list1[key]);
                    min = key + map2[list1[key]];
                }
            }
        }
        return res;
    }
};

// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
// 案例:
// s = "leetcode"
// 返回 0.
// s = "loveleetcode",
// 返回 2.
class Solution3 {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map1;
        for (int i = 0; i < s.size(); i++) {
            map1[s[i]] = i;
        }//最后一次出现的下标
        for (int i = 0; i < s.size(); i++)
        {
            if (s.find(s[i]) == map1[s[i]]) {
                return i;
            }
        }
        return -1;
    }
};

// 给定两个数组，编写一个函数来计算它们的交集。
// 示例 1:
// 输入: nums1 = [1,2,2,1], nums2 = [2,2]
// 输出: [2,2]
// 示例 2:
// 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// 输出: [4,9]
class Solution4 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            intersect(nums2, nums1);
        }
        vector<int> same;
        unordered_map<int, int> m1;
        for (int key : nums1) {
            if (m1.count(key) > 0) {
                m1[key]++;
            }
            else m1[key] = 1;
        }
        for (int key : nums2) {
            if (m1.count(key) > 0 && m1[key] > 0) {
                same.push_back(key);
                m1[key]--;
            }
        }
        return same;
    }
};

// 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。
// 示例 1:
// 输入: nums = [1,2,3,1], k = 3
// 输出: true
// 示例 2:
// 输入: nums = [1,0,1,1], k = 1
// 输出: true
// 示例 3:
// 输入: nums = [1,2,3,1,2,3], k = 2
// 输出: false
class Solution5 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        if (nums.size() <= 1) return false;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(nums[i]) > 0) {
                hash[nums[i]] = i - hash[nums[i]];
                if (hash[nums[i]] <= k) {
                    return true;
                    break;
                }
            }
            else hash[nums[i]] = i;
        }
        return false;
    }
};

