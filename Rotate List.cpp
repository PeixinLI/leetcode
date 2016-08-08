/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	int len;
    	ListNode* th = head;
    	while(th){
    		len++;
    		th = th->next;
    	}
    	if(len == 0 || len == 1)
    		return head;

    	int move = k % len;

    	if(move == 0)
    		return head;

    	ListNode* slow = head;
    	ListNode* fast = head;
    	while(move--){
    		fast = fast->next;
    	}
    	while(fast->next){
    		fast = fast->next;
    		slow = slow->next;
    	}

    	ListNode* nh = slow->next;
    	slow = slow->next;

    	slow->next = NULL;
    	fast->next = head;

    	return nh;


    }
};