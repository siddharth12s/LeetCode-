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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast=head, *slow=head, *ptr=head;
        int i=k;
        while(fast and i){
            fast=fast->next;
            i--;
        }
        for(auto i=1;i<k;i++)
            ptr=ptr->next;
        while(fast){
            slow=slow->next;
            fast=fast->next;
        }
        int x= slow->val;
        slow->val=ptr->val;
        ptr->val=x;
        return head;
    }
};