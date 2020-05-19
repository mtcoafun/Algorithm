#include <stdio.h>
#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}; 

// 反转一个单链表。
// 示例:
// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
// 进阶:
// 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 迭代法
        // ListNode* pre = NULL;
        // ListNode* cur = head;
        // while (cur != NULL) {
        //     ListNode* nextTemp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = nextTemp;
        // }
        // return pre;
        // 递归法
        if (!head || !head->next) return head;
        ListNode* cur = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
};