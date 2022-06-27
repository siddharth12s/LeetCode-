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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast=head, *slow=head,*prev=NULL;
        if(head->next==NULL){
            fast->next=NULL;
            head=NULL;
            delete fast;
            return head;
        }
        
        while(fast and fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=slow->next;
        slow->next=nullptr;
        delete slow;
        return head;
    }
};