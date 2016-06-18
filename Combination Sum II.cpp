//backtracking

class Solution {
public:
    vector<vector<int>> _Solution;
    vector<int> one_solution;
    void Find_Solution(vector<int>& candidates, int k, int target);
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
    
    int i = k;
    int j = i;
    while( candidates[i] == candidates[j] && j < L) j++;
    
    for(int n = 0; n <= j-i; n++){
        if(n > 0)
            one_solution.push_back(candidates[i]);
        Find_Solution(candidates, j, target - candidates[i]*n);
    }
    for(int n = i; n < j; n++)
        one_solution.pop_back();
    
    
    return;
    
}