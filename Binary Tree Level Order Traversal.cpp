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
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> res;
    	if(!root)
    		return res;

    	queue<TreeNode*> v;
    	v.push(root);
    	while(!v.empty()){
    		vector<int> t;
    		queue<TreeNode*> temp;
    		while(!v.empty()){
    			TreeNode* tnode = v.front();
    			v.pop();
    			t.push_back(tnode->val);
    			if(tnode->left != NULL)
    				temp.push(tnode->left);
    			if(tnode->right != NULL)
    				temp.push(tnode->right);
    		}
    		res.push_back(t);
    		v = temp;
    	}

    	return res;
        
    }
};