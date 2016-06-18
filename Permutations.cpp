class Solution {
public:
    vector<vector<int>> permutations;
    vector<int> one_ans;
    vector<vector<int>> permute(vector<int>& nums) {
        findpermute(0, nums);
        return permutations;
        
    }
    void findpermute(int begin, vector<int>& nums){
        if(begin == nums.size() - 1){
            permutations.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++ ){
            swap(nums[begin], nums[i]);
            findpermute(begin+1, nums);
            swap(nums[begin], nums[i]);
        }
    }
    
    void swap(int& a, int& b){
        int tmp;
        tmp = a;
        a = b;
        b =tmp;
        return;
    }
};