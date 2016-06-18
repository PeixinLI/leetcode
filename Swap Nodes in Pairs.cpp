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
    ListNode* swapPairs(ListNode* head) {
        ListNode* thead = head;
        if(head == NULL) return head;
        if(thead->next){
            ListNode* temp = thead->next;
            thead->next = temp->next;
            temp->next = thead;
            thead = temp;
            head = thead;
        }
        else
            return head;
        
        while(thead->next->next){
            ListNode* tthead = thead->next->next;
            cout << tthead->val<<endl;
            if(tthead->next){
                cout << tthead->next->val<<endl;
                ListNode* temp = tthead->next;
                tthead->next = temp->next;
                temp->next = tthead;
                tthead = temp;
            }
            else
                break;
            thead->next->next = tthead;
            thead = tthead;
        }
        
        return head;
        
    }
};