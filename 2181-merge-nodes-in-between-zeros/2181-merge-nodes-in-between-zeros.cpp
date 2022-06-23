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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* start=head;
        ListNode* end = head->next;
        
        vector<int> v;
        
        while(end){
            if(end->val!=0){
                end=end->next;
                continue;
            }
            int sum=0;
            while(start!=end){
                start=start->next;
                sum+=start->val;
            }
            
            v.push_back(sum);
            end=end->next;
        }   
        
        ListNode* newhead = new ListNode(v[0]);
        ListNode* ans=newhead;
        
        for(auto i=1;i<v.size();i++){
            newhead->next= new ListNode(v[i]);
            newhead=newhead->next;
        }
        return ans;
    }
};