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
        auto prev_ptr = head;
        
        auto cur_ptr = head->next;
        // int cnt = 0;
        prev_ptr->next = NULL;
        while(cur_ptr->next!=NULL ){
            cout<<"curptr"<<cur_ptr->val<<endl;
            nextPtr = cur_ptr->next;
            cur_ptr->next = prev_ptr;
            prev_ptr = cur_ptr;
            cur_ptr = nextPtr;
            // cnt++;
        }
        cur_ptr->next = prev_ptr;
        return cur_ptr;
    }
};
