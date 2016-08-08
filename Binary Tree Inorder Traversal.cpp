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
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode*> nodes; // node to be visited
        TreeNode* cur; // cur node
        vector<int> res;

        if(root == NULL)
            return res;

        cur = root;
        while(cur || !nodes.empty()){
            if(cur != NULL){
                nodes.push(cur);
                cur = cur->left;
            }
            else{
                cur = nodes.top();
                res.push_back(cur->val);
                nodes.pop();
                cur = cur->right;

            }

        }

        return res;

        
    }
};