/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL) return ;
        if(head->next == NULL) return;
        if(head->next->next == NULL) return ;
        auto ptrend = head;
        auto ptrendprev = head;
        while(ptrend->next != NULL) {
            ptrendprev = ptrend;
            ptrend = ptrend->next;   
        }
        ptrendprev->next = NULL;
        auto nexthead = head->next;
        head->next = ptrend;
        reorderList(nexthead);
        ptrend->next = nexthead;
    }
};
