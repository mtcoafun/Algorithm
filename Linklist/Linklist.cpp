#include <stdio.h>
#include <vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}; 

// 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
// 示例：
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4
// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
// 示例:
// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(-1);
        ListNode* p3 = l3;
        while(l1 && l2) {
            if (l1->val <= l2->val) {
                p3->next = l1;
                l1 = l1->next;
            }
            else {
                p3->next = l2;
                l2 = l2->next;
            }
            p3 = p3->next;
        }
        p3->next = l1 ? l1 : l2;
        return l3->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for (size_t i = 0; i < lists.size(); ++i) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};