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
    int pairSum(ListNode* head) {
        
        ListNode* temp=head;
        vector<int> v;
        
        while(temp){ v.push_back(temp->val); temp=temp->next;}
        int ans=INT_MIN;
        for(auto i=0;i<(v.size()/2);i++){
            ans= max(ans,v[i]+v[v.size()-1-i]);
        }
        return ans;
    }
};