class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int move = 0;
    	int size = nums.size();
    	if(size == 0 || size == 1)
    		return;

    	for(int i = 0; i < size; i++){
    		if(nums[i] == 0){
    			move++;
    			continue;
    		}
    		nums[i-move] = nums[i];
    	}

    	for(int i = size - move; i < size; i++){
    		nums[i] = 0;
    	}

    	return ;
        
    }
};