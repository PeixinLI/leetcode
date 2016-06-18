class Solution {
public:
    vector<vector<int>> permutation;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        find_permutation(0, nums);
        return permutation;
        
    }
    void find_permutation(int begin, vector<int> nums){
        if(begin == nums.size() - 1){
            permutation.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++){
            if(i != begin && nums[i] == nums[begin]) continue;
            swap(nums[begin], nums[i]);
            find_permutation(begin+1, nums);
        }
        return;
    }
    
    void swap(int& a, int& b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
        return ;
    }
};