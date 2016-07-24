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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* temp = new ListNode(0);
      temp->next = head;
      ListNode* h = temp;

      while (temp->next) {
        ListNode* t = temp->next;
        while (t->next != NULL && t->next->val == temp->next->val)
          t = t->next;

        if(t != temp->next)
          temp->next = t->next;
        else
          temp = temp->next;
      }

      return h->next;

    }
};
