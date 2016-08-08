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
    int maxPathSum(TreeNode* root) {
    	int res = 0x80000000;

    	maxsum(root, res);

    	return res;
    }

    int maxsum(TreeNode* root, int& res){
    	if(root == NULL)
    		return 0;

    	int left = maxsum(root->left, res);
    	int right = maxsum(root->right, res);
    	
    	if(left < 0) left = 0;
    	if(right < 0) right = 0;

    	if((left + right + root->val) > res)
    		res = left + right + root->val;

    	return max(left, right) + root->val;

    }
};