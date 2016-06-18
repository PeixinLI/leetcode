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
    int countNodes(TreeNode* root) {
        if( root == NULL) return 0;
        int lh = 0, rh = 0;
        lh = get_left_hight(root);
        rh = get_right_hight(root);
        
        if(lh == rh) return (1<<(lh)) -1;
        
        else return 1 + countNodes(root->left) + countNodes(root->right);
        
        
    }
    
    int get_left_hight(TreeNode* root){
        TreeNode *p = root;
        int h = 0;
        while(p){
            h++;
            p = p->left;
        }
        return h;
    }
    
    int get_right_hight(TreeNode* root){
        TreeNode *p = root;
        int h = 0;
        while(p){
            h++;
            p = p->right;
        }
        return h;
    }
    
};