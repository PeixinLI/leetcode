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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        stack<vector<int>> rres;

        queue<TreeNode*> q;

        if(root != NULL)
            q.push(root);
        

        while(!q.empty()){
            int num = q.size();
            vector<int> temp;
            while(num--){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            rres.push(temp);
        }

        while(!rres.empty()){
            res.push_back(rres.top());
            rres.pop();
        }
        return res;
        
    }
};