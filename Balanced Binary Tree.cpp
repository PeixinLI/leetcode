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
    bool isBalanced(TreeNode* root){
    	int h = treeheight(root);
    	if(h == -1)
    		return false;

    	return true;
        
    }

    int treeheight(TreeNode* root){
    	if(root == NULL)
    		return 0;

    	int lh = treeheight(root->left);
    	int rh = treeheight(root->right);

    	if(abs(lh - rh) > 1 || rh == -1 || lh == -1)
    		return -1;

    	return max(lh, rh) + 1;
    } 
};