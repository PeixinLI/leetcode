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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int>> res;
    	vector<TreeNode*> v;

    	if(root != NULL)
    		v.push_back(root);

    	while(!v.empty()){
    		vector<TreeNode*> temp;
    		vector<int> sibling;
    		for(int i = 0; i < v.size(); i++){
    			sibling.push_back(v[i]->val);
    			if(v[i]->left != NULL)
    				temp.push_back(v[i]->left);
    			if(v[i]->right != NULL)
    				temp.push_back(v[i]->right);
    		}
    		v = temp;
    	}  

    	for(int i = 2; i < res.size(); i += 2){
    		reverseVector(res[i]);
    	}

    	return res; 
    }

    void reverseVector(vector<int>& v){
    	int i = 0;
    	int j = v.size() - 1;

    	while(i <= j){
    		int temp = v[i];
    		v[i] = v[j];
    		v[j] = temp;
    		i++;
    		j--;
    	}
    	return;
    }
};