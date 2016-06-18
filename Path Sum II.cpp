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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        return res;
    }
    
    void findpath(TreeNode* root, int sum, vector<int> & path){
        if(root == NULL || sum < 0) return;
        if(root->left == NULL && root->right == NULL&& root->val == sum)
            res.push_back(path);
        
        path.push_back(root);
        findpath(root->left, sum - root->val, path);
        findpath(root->right, sum - root->val, path);
        path.pop();
        
        return;
        
    }
};