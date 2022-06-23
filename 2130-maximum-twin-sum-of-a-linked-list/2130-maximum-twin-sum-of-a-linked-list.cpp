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
    void reverseLL(ListNode **head) {
        ListNode *curr = *head;
        ListNode *prevNode = NULL;
        ListNode *nextNode;
        
        while(curr) {
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }
        
        *head = prevNode;
        
    }
	
int pairSum(ListNode* head) {
	
	 ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow = slow->next;
        
        reverseLL(&slow);
        int maxVal = 0;
        while(slow) {
            maxVal = max(maxVal,head->val + slow->val);
            slow = slow->next;
            head = head->next;
        }
        
        return maxVal;
	}
};