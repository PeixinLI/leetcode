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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        stack<TreeNode*> visit;
        TreeNode* lastVisit;

        while(root || !visit.empty()){
            if(root){
                visit.push(root);
                root = root->left;
            }
            else{
                TreeNode* tmp = visit.top();
                if(tmp->right && lastVisit != tmp->right){
                    root = tmp ->right;
                }
                else{
                    res.push_back(tmp->val);
                    lastVisit = tmp;
                    visit.pop();
                }
            }

        }
        
        return res;
    }
};