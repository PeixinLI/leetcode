/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //we use inordered traversal to solve this problem
 //If we use in-order traversal to serialize a binary search tree, we can
//get a list of values in ascending order.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	TreeNode* prev = NULL; // previously visited nodes
    	
    	return valid(root, prev);
        
    }
    bool valid(TreeNode* node, TreeNode* &prev){
    	if(node == NULL)
    		return true;
    	if(!valid(node->left, prev))
    		return false;

    	// VISIT NODE
    	if(prev != NULL && node->val <= prev->val)
    		return false;

    	//After visit the node
    	prev = node;

    	if(!valid(node->right, prev))
    		return false;

    	return true;

    }
};