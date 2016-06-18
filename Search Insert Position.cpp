class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
       return BinarySearchPosition(nums, 0, size-1, target);
    }
    
    int BinarySearchPosition(vector<int> & nums, int begin, int end, int target){
        if(begin == end){
            if(nums[begin] == target)
                return begin;
            else if(nums[begin] > target)
                return begin;
            else if(nums[begin] < target)
                return begin+1;
        }
        
        int med = (begin + end) / 2;
       
        if(nums[med] == target)
            return med;
        
        if(nums[med] > target)
            return BinarySearchPosition(nums, begin, med, target);
        
        if(nums[med] < target)
            return BinarySearchPosition(nums, med+1, end, target);
    }
};