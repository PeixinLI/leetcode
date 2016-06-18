class Solution {
public:
    vector<vector<int>> res;
    vector<int> one_res;
    vector<vector<int>> combine(int n, int k) {
        combination(n, k, 0);
        return res;
        
    }
    void combination(int n, int k, int i){
        if(k == 0 & n == 0) {
            res.push_back(one_res);
            return;
        }
        if(n-i < k) return;
        
        combination(n, k, i+1);
        for(int j = i; j < n; j++){
            res.push_back(j);
            combination(n, k-1, j);
            res.pop_back();
        }
        
        return;
    }
};