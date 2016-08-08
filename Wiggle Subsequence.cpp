class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	int size = nums.size();
    	if(size == 0)
    	    return 0;
    	vector<int> pos(size, 0);
    	vector<int> neg(size, 0);

    	for(int i = 1; i < size; i++){
    		if(nums[i-1] > nums[i]){
    			neg[i] = neg[i-1] + 1;
    			pos[i] = neg[i-1];
    		}
    		else if(nums[i-1] < nums[i]){
    			pos[i] = pos[i-1] + 1;
    			neg[i] = pos[i-1];
    		}
    		else if(nums[i-1] == nums[i]){
    		    pos[i] = pos[i-1] + 1;
    			neg[i] = neg[i-1] + 1;
    		}
    	}
    	
    	int d = min(pos[size-1], neg[size-1]);
        
        return size - d;
    }
};