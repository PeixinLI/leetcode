//permutation 排列组合
// if the numbers are in descending order, return the reverse order. Else find the first element that breaks the order, the position is j. swap it with the smallest num that is larger than the  nums[j]
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size == 0 || size == 1)
            return nums;
        int pos1, pos2;
        for(pos1 = size - 2; pos1 >= 0; pos1--){
            if(nums[pos1] < nums[pos1 + 1]){
                break;
            }
        }
        
        if(pos1 == -1){ // no num breaks the law
            sort(nums.begin(), nums.end());
            return nums;
        }
        
        for(int pos2 = size - 1; pos2 > pos1; pos2--){
            
            if(nums[pos2] > nums[pos1]){
                swap(nums[pos1], nums[pos2]);
                break;
            }
        }
        sort(nums.begin()+pos1+1,nums.end());
        return nums;
    }
    
};