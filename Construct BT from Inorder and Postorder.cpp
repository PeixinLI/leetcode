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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	int size1 = inorder.size();
    	int size2 = postorder.size();

    	return build(inorder, 0 , size1, postorder, 0, size2);
        
    }

    TreeNode* build(vector<int>& inorder, int begin1, int end1, vector<int>& postorder, int begin2, int end2){

    	if(begin1 >= end1 || begin2 >= end2)
    		return NULL;

    	int rval = postorder[end2-1];

    	vector<int>::iterator ri = find(inorder.begin(), inorder.end(), rval);

    	int lnum = ri - (inorder.begin() + begin1);

    	TreeNode* root = new TreeNode(rval);
    	TreeNode* left = build(inorder, begin1, begin1+lnum, postorder, begin2, begin2+lnum);
    	TreeNode* right = build(inorder, begin1+lnum+1, end1, postorder, begin2+lnum, end2-1);
    	
    	root->left = left;
    	root->right = right;
    	return root;
    }
};