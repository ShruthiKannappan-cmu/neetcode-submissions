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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode * curptr = NULL;
        while(list1!= NULL || list2!= NULL){
            ListNode * ptr = NULL;
            int minVal;
            if(list1!= NULL){
                ptr = list1;
            } 
            if(list2!=NULL){
                if(ptr == NULL){
                    ptr = list2;
                    list2 = list2->next;
                } else {
                    if(ptr->val > list2->val){
                        ptr = list2;
                        list2 = list2->next;
                    } else {
                        list1 = list1->next;
                    }
                }
            } else {
                list1 = list1->next;
            }
            ptr->next = NULL;
            if(curptr == NULL){
                head = ptr;
                curptr = ptr;
            } else {
                curptr->next = ptr;
                curptr = ptr;
            }
        }
        return head;
    }
};
