/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// first try lose some case when the right-sub-tree is null

/*class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        while(root){
            res.push_back(root->val());
            if(root->right())
                root = root->right();
            else
                root = root->left();
        }
        
        return res;
    }
};*/
// use level to check if the rightest node of this level has benn add
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        AddRightNode(root, res, 0);
        return res;
    }
    void AddRightNode(TreeNode* root, vector<int>& res, int level){
        if(!root)
            return;
        if(res.size() <= level)res.push_back(root->val);
        AddRightNode(root->right, res, level+1);
        AddRightNode(root->left, res, level+1);
        return;
    }
};

