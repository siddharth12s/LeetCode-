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
   ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } 
        l2->next = merge(l1, l2->next);
        return l2;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* slow = head, *fast = head;
        ListNode* prior;
        while(fast != NULL && fast->next != NULL) {
            prior = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prior->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
};