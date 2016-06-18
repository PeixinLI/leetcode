class Solution {
public:
    vector<int> Range(2);
    vector<int> searchRange(vector<int>& nums, int target) {
        Range[0] = -1;
        Range[1] = -1;
        int size = nums.size();
        if(size == 0);
        return Range;
    }
    
    void BinarySearchRange(vector<int>& nums, int begin, int end, int target){
        if(begin == end){
            if(nums[begin] != target)
                return;
        }
        int med = (begin + end) / 2;
        
        if(nums[med] == target){
            for(int i = med; i >= begin; i --){
                if(nums[i] != target) break;
                Range[0] = i;
            }
            
            for(int j = med; j<= end; j++){
                if(nums[j] != target) break;
                Range[1] = j;
            }
            return ;
        }
        
        if((nums[med] > target) && (med - 1 >= begin))
            BinarySearchRange(nums, begin, med -1, target);
        else if((nums[med] < target)&& (med + 1 >= end))
            BinarySearchRange(nums, med + 1, end, target);
        
        return;
        
        
    }
};