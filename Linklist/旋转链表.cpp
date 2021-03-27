// 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
// 示例 1：
// 输入：head = [1,2,3,4,5], k = 2
// 输出：[4,5,1,2,3]
// 示例 2：
// 输入：head = [0,1,2], k = 4
// 输出：[2,0,1]
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {} 
};

class Solution {
public:

    ListNode* helper(ListNode* head) {
        ListNode* p = head;
        ListNode* n = head->next;
        while(n->next) {
            p = p->next;
            n = n->next;
        }
        n->next = head;
        p->next = nullptr;
        return n;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        // 方法一
        // if(!head || !(head->next)) return head;
        // ListNode* p = head;
        // int len = 1, times = 0;
        // while(p->next) {
        //     p = p->next;
        //     len++;
        // }
        // times = k % len;
        // ListNode* res = head;
        // for(int i = 0; i < times; i++) {
        //     res = helper(res);
        // }
        // return res;

        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        int n = 1;
        ListNode* iter = head;
        while (iter->next != nullptr) {
            iter = iter->next;
            n++;
        }
        int add = n - k % n;
        if (add == n) {
            return head;
        }
        iter->next = head;
        while (add--) {
            iter = iter->next;
        }
        ListNode* ret = iter->next;
        iter->next = nullptr;
        return ret;
    }
};