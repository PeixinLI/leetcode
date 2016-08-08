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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	int size1 = preorder.size();
    	int size2 = inorder.size();

    	return build(preorder, 0, size1, inorder, 0, size2);
    }

    TreeNode* build(vector<int>& preorder, int begin1, int end1, 
    	vector<int> &inorder, int begin2, int end2){

    	if(begin1 >= end1 || begin2 >= end2)
    		return NULL;

    	int rtval = preorder[begin];

    	vector<int>::iterator rti = find(inorder.begin() + begin2, inorder.end() + end2, rtval);

    	// have a lot of problem in this step  - override
    	int lnum = rti - (inorder.begin() + begin2);

    	TreeNode* root = new TreeNode(rtval);

    	TreeNode* left = build(preorder, begin1+1, begin1+1+lnum, inorder, begin2, begin2+lnum);
    	TreeNode* right = build(preorder, begin1+1+lnum, end, inorder, begin2+lnum+1, end);

    	root->left = left;
    	root->right = right;

    	return root;

    }
};  