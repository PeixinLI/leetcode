
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
    
    vector<TreeNode*> generateTrees(int n) {
        
        return generate(1,n);
    }
    vector<TreeNode*> generate(int begin, int end){
        vector<TreeNode*> trees;
        if(begin > end){
            trees.push_back(NULL);
            return trees;
        }
        
        for(int i = begin;i <= end; i++ ) {//select the root
            vector<TreeNode*> l_tree = generate(begin, i-1);
            vector<TreeNode*> r_tree = generate(i+1, end);
            //TreeNode* root = new TreeNode(i);  if I Put the root here the result will noe be right cause the root will change
            
            for(int j = 0; j < l_tree.size(); j++)
                for(int k = 0; k < r_tree.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    TreeNode* left = l_tree[j];
                    TreeNode* right = r_tree[k];
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
        }
        
        return trees;
    }
    
};