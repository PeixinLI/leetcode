class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
    	int sum = 0;
    	int maxsum =  -INFINITY;
    	
    	for(int i = 0; i < size; i++){
    		sum = sum + nums[i];
    		maxsum = max(sum, maxsum);
    		sum = sum > 0 ? sum : 0;
    	}

    	return maxsum;
    }
};