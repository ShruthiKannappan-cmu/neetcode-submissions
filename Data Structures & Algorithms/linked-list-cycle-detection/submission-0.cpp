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
    bool hasCycle(ListNode* head) {
        if(head == NULL) return false;
        if(head->next == NULL) return false;
        auto ptr1 = head;
        auto ptr2 = head->next;
        while((ptr2!= NULL) && (ptr1!=NULL)){
            if(ptr1 == ptr2) return true;
            if(ptr1->next == NULL){
                return false;
            }
            ptr1 = ptr1->next;
            if(ptr2->next == NULL) return false;
            if(ptr2->next->next == NULL) return false;
            ptr2 = (ptr2->next)->next;
        }
        return false;
    }
};
