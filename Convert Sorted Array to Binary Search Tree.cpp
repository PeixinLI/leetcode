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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	int size = nums.size();

    	return buildBST(nums, 0, size);
        
    }

    TreeNode* buildBST(vector<int>& nums, int begin, int end){
    	if(begin >= end)
    		return NULL;

    	int mid = (begin + end)/2;

    	TreeNode* root = new TreeNode(nums[mid]);

    	TreeNode* left = buildBST(nums, begin, mid);
    	TreeNode* right = buildBST(nums, mid+1, end);

    	root->left = left;
    	root->right = right;

    	return root;
    }
};