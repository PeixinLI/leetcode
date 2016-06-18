/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// rememer how to use the pointer and construcion fuction
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* out;
        out = & head;
        int t = 0;
        while( l1  || l2  || t){
            out->next = new ListNode (0);
            out = out->next;
            if(l1) {
                out->val += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                out->val += l2->val;
                l2 = l2->next;
            }
            if(t) out->val += t;
            t = out->val /10;
            out->val = out->val % 10;
        }
        return head.next;
    }
    
    
};