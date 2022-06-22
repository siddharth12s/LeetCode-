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
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        
        ListNode* temp=head;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        
        sort(ans.begin(),ans.end());
        for(auto i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        temp=head;
        int i=0;
        while(temp){
            temp->val= ans[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};