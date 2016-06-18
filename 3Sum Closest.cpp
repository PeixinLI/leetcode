class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_sum = 0;
        int min_d = INT_MAX;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        for(int first = 0; first < N -2; first++){
            int second = first + 1;
            int third = N -1;
            int sum;
            while(second < third){
                sum = nums[first] + nums[second] + nums[third];
                if(sum < target)
                    second++;
                else if(sum > target)
                    third--;
                else if(sum == target){
                    return target;
                }
                int d = sum > target? (sum-target):(target-sum);
                if( d < min_d){
                    min_d = d;
                    closest_sum = sum;
                }
            }
        }
        
        return closest_sum;
        
    }
};