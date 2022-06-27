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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head, *slow=head, *prev=nullptr;
        if(fast->next==nullptr and n==1){
            ListNode* temp=head;
            head=NULL;
            delete temp;
            return head;
        }
        while(fast and n){
            fast=fast->next;
            n--;
        }
        while(fast){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        if(prev){
            prev->next=slow->next;
            slow->next=nullptr;
            delete slow;
            return head;
        }
        else{
            head=slow->next;
            return head;
        }
    }
};