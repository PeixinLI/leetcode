//backtracking

class Solution {
public:
    vector<vector<int>> _Solution;
    vector<int> one_solution;
    void Find_Solution(vector<int>& candidates, int k, int target);
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        Find_Solution(candidates, 0, target);
        
        return this->_Solution;
    }
};

void Solution::Find_Solution(vector<int>& candidates, int k, int target){
    int L = candidates.size();
    
    if(target == 0) {
        this->_Solution.push_back(one_solution);
        return;
    }
    
    if(k == L || target < 0) return;
    
    for(int i = k; i < candidates.size(); i++){
        one_solution.push_back(candidates[i]);
        Find_Solution(candidates, i, target - candidates[i]);
        one_solution.pop_back();
    }
    
    return;
    
}