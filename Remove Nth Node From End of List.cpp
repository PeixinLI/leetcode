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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* h1 = new ListNode(0);
      ListNode* h2 = new ListNode(0);
      ListNode* h3 = new ListNode(0);
      h1->next = head;
      h2->next = head;
      h3 = h2;

      for(int i = 0; i < n; i++){
        h1 = h1->next;
      }
      while(h1->next){
        h1 = h1->next;
        h2 = h2->next;
      }

      h2->next = h2->next->next;

      return h3->next;

    }
};
