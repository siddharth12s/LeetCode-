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
        ListNode* cur= *head;
        ListNode* prev=nullptr;
        ListNode* nextn;
        
        while(cur){
            nextn=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextn;
        }
        *head=prev;
    }
    int pairSum(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast= head;
        ListNode* prev=NULL;
        
        while(fast and fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        reverseLL(&slow);
        int ans=INT_MIN;
        ListNode* ptr1=head, *ptr2 = slow;
        while(ptr1){
            ans=max(ans, ptr1->val + ptr2->val);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
        reverseLL(&slow);
        prev->next=slow;
        
        return ans;
    
    }
};