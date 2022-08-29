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
    
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL or (head->next==NULL and head->val==val))  return nullptr;
        
        
        while(head and head->val==val)
            head=head->next;
        
        ListNode* temp=head;
        ListNode* slow=NULL;
        while(temp){
            if(temp->val==val){
                ListNode* temp2;
                slow->next=temp->next;
                temp2=temp;
                temp=temp->next;;
                temp2->next=NULL;
                delete temp2;
            }
            else{
                slow=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};