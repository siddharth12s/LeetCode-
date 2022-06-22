/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head; ListNode* slow=head; ListNode* cur= head;
        while(fast and fast->next){
            fast=fast->next->next;  slow=slow->next;
            if(fast==slow){  
                while(slow!=cur){ slow=slow->next; cur=cur->next; } 
                           return cur;}
        }
        return nullptr;
    }
};