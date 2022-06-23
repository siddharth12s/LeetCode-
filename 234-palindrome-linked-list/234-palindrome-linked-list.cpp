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
    
    void reverseLL(ListNode** head){
        ListNode* prev=nullptr;
        ListNode* cur= *head;
        ListNode* nextn;
        
        while(cur){
            nextn=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextn;
        }
        *head=prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast and fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
       // prev->next=nullptr;
        reverseLL(&slow);
        
        ListNode* ptr1=head;
        ListNode* ptr2=slow;
        
        while(ptr1 and ptr2){
            if(ptr1->val!=ptr2->val)
                return false;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return true;
    }
};