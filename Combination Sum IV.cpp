class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	vector<int> seqs(target + 1, 0);
    	int size = nums.size();

    	seqs[0] = 1;
    	
    	for(int i = 1; i <= target; i ++){
    		for(int j = 0; j < size; j++){
    			if(i - nums[j] >= 0){
    				seqs[i] += seqs[i - nums[j]];
    			}
    		}
    	}

    	return seqs[target];
    }
};