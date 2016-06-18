/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// two main idea : first use priority queue; second use divide and conquer
// first use pririty_queue
// priority_queue<Type, Container, Functional> keeps internally a comparing function and a container object as data, which are copies of comp and ctnr respectively.
// return greater
class Solution {
public:
    struct cmp{
        bool operator()(ListNode* node1, ListNode* node2){
            return node1->val > node2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int N = lists.size();
        if(N == 0) return NULL;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i = 0; i < N; i++){
            if(lists[i])
                q.push(lists[i]);
        }
        
        ListNode head(0); // temp head
        ListNode* thead = & head;
        while(!q.empty()){
            ListNode *p = q.top();
            q.pop();
            thead->next = p;
            thead = thead->next;
            if(p->next){
                q.push(p->next);
            }
        }
        
        return head->next;
    }
};