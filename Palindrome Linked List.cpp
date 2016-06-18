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
    bool isPalindrome(ListNode* head) {
    	if(head == NULL or head->next == NULL) return true;
    	ListNode* mid = head;
    	ListNode* end = head;
    	while(end){
    		end = end->next;
    		if(end) {
    			mid = mid->next;
    			end = end->next;
    			}
    		}
    	ListNode* head1 = reverse_list(mid);
    	ListNode* head2 = head;
    	ListNode* temp = head1;
    	
    	while(head1&&head2){
    		if(head1->val != head2->val){ 
    			reverse_list(temp);
    			return false;
    			}
    			head1 = head1->next;
    			head2 = head2->next;
    		}
    	
    	reverse_list(temp);
    	return true;
    	       
    }
};

ListNode* reverse_list(ListNode* head){
	ListNode* rhead = head, *nextnode = head->next;
	rhead->next = NULL;
	while(nextnode){
		ListNode*temp = nextnode->next;
		nextnode->next = rhead;
		rhead = nextnode;
		nextnode = temp;
		}
	 return rhead;
	}