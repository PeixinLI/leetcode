class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        int N = nums.size();
        for(int first = 0; first < N - 3; first++){ // for the first number
            for(int second = first + 1; second < N - 2; second ++){
                int third = second+1;
                int fourth = N -1;
                int sum;
                while(third < fourth){
                    sum = nums[first] + nums[second] + nums[third] + nums[fourth];
                    if(sum < target)
                        third ++;
                    else if(sum > target)
                        fourth --;
                    else if(sum == target){
                        res.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                        while(nums[third] == nums[third+1]) // ignore the same number;
                            third ++;
                        third ++;
                    }
                    
                }
                while(nums[second] == nums[second+1])
                    second ++;
            }
            while(nums[first] == nums[first+1])
                first++;
        }
        
        return res;
    }
};

// -2 -1 0 0 1 2