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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return;
        ListNode* ehead = head->next;
        if(!ehead) return;
        ListNode* temp1 = head, temp2 = ehead;
        while(temp1->next){
            temp2 = temp1->next;
            temp1->next = temp2->next;
            temp1 = temp1->next;
            temp2 = temp1->next;
        }
        temp1->next = ehead;
        return ehead;
    }
};