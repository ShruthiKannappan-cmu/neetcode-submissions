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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        auto nextPtr = head->next;
        if(nextPtr == NULL) return head;
        auto reversed_next = reverseList(nextPtr);
        head->next = NULL;
        auto cur_ptr = reversed_next;
        while(cur_ptr->next != NULL) cur_ptr = cur_ptr->next;
        cur_ptr->next = head;
        return reversed_next;
    }
};
