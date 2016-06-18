/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    TreeNode* pnode = root;
    stack<TreeNode*> nodes;
    int n=0;
    
    while(pnode || !nodes.empty()){
    	while(pnode){
    		nodes.push(pnode);
    		pnode = pnode -> left;
    		}
    		pnode = nodes.top();
    		n++;
    		nodes.pop();
    		if(n == k) return pnode->val;
    		pnode = pnode->right;    		    		
    	}  
    
    return -1;
    	 
    }
};