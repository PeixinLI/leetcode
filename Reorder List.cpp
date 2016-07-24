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
    void reorderList(ListNode* head) {
    	if(!head && !head->next)
    		return;
    	ListNode* fhead = head;
    	ListNode* shead = head;
    	while(fhead->next){
    		fhead = fhead->next;
    		if(fhead->next){
    	       shead = shead->next;
    	       fhead = fhead->next;
    		}
    	}

    	ListNode* mid = shead->next;
    	shead->next = NULL;
    	ListNode* rmid = NULL; // reverse mid node 
    	while(mid){
    		ListNode* temp = mid;
    		mid = mid->next;
    		temp->next = rmid;
    		rmid = temp;
    	}

    	ListNode* thead;
    	while(head && rmid){
    		cout<<head->val<<endl;
    		cout<<rmid->val<<endl;
    		thead = head;
    		head = head->next;
    		thead = thead->next;
    		thead = rmid;
    		rmid = rmid->next;
    		thead = thead->next;
    	}
    }
};