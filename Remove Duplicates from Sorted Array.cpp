class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
        	return 0;
        if(size == 1)
        	return 1;

        int i = 1;
        int temp = nums[0]
        while(i < nums.size()){
        	if(nums[i] == temp)
        		nums.erase(nums.begin() + i );
        	else {
        		temp = nums[i]
        		i ++;
        	}
        }
        return i;
    }
};