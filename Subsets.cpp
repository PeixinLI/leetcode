class Solution {
public:
    vector<vector<int>> Subsets;
    vector<int> one_Subset;
    vector<vector<int>> subsets(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i<= N; i++){
            find_Subset(i, 0, N-1, nums);
        }
        
        return Subsets;
        
    }
    
    void find_Subset(int k, int begin, int end, vector<int>& nums){
        if(begin +k -1 > end) return;
        
        if(k == 0){
            Subsets.push_back(one_Subset);
            return;
        }
        
        find_Subset(k, begin+1, end, nums);
        one_Subset.push_back(nums[begin]);
        find_Subset(k-1, begin+1, end, nums);
        one_Subset.pop_back();
        
        
    }
};