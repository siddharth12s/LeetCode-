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
        
        if(list1==nullptr and list2==nullptr)
            return nullptr;
        
        else if(list1==nullptr and list2!=nullptr)
            return list2;
        
        else if(list1!=nullptr and list2==nullptr)
            return list1;
        
        ListNode* i= list1;
        ListNode* j= list2;
        ListNode* k = new ListNode();
        ListNode* ans= k;
        while(i!=nullptr and j!=nullptr){
            
            if(i->val<j->val){
                k->val=i->val;
                k->next= new ListNode();
                k=k->next;
                i=i->next;
            }
            else{
                k->val=j->val;
                k->next= new ListNode();
                k=k->next;
                j=j->next;
            }
        }
        while(i!=nullptr){
                k->val=i->val;
                k->next= new ListNode();
                k=k->next;
                i=i->next;
        }
        while(j!=nullptr){
                k->val=j->val;
                k->next= new ListNode();
                k=k->next;
                j=j->next;
        }
        ListNode* temp=ans;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        temp->next=nullptr;
        return ans;
    }
};