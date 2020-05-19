#include <stdio.h>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        int i = 1;
        while (ptr != nullptr) {
            if (i == k) {
                
                i = 0;
            }
            i++;
            ptr = ptr->next;
        }
        return head;
    }
};