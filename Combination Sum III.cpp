//backtracking

class Solution {
public:
    vector<vector<int>> _Solution;
    vector<int> one_solution;
    void Find_Solution(int a, int k, int n);
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        Find_Solution(0, k, n);
        
        return this->_Solution;
    }
};

void Solution::Find_Solution(int a, int k, int n){//from a
    
    if(n == 0 && k == 0) {
        _Solution.push_back(one_solution);
        return;
    }
    
    if(a > 9 || k == 0 || n < 0 || k > n) return;
    
    one_solution.push_back(a);
    Find_Solution(a+1, k-1, n-k);
    one_solution.pop_back();
    Find_Solution(a+1, k , n);
    
    
    return;
    
}