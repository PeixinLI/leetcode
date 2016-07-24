/*class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int size = nums.size();

    	for(int i = 0; i < size; i ++)
    		if(nums[i] == target)
    			return i;

    	return -1;
        
    }
};*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int size = nums.size();

    	int i = 0;
    	int j = size; 
    	while(i < j){
    		int k = (i+j)/2;

    		if(nums[k] == target)
    			return k;

    		if((target > nums[k] && nums[k] >= nums[i])  
    			|| (target > nums[k] && nums[k] <= nums[j]) 
    			|| (target < nums[k] && nums[k] >= nums[j]))
    			i = k;

    		else 
    			j = k;
    	}

    	return -1;
        
    }
};