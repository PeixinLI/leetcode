// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         int size = nums.size();
//
//         if(size == 1 && target != nums[0])
//           return false;
//
//         int i = 0;
//         int j = size -1;
//         while(i <= j){
//           k = (i+j)/2;
//           if(nums[k] == target)
//             return true;
//
//
//         }
//
// 
//         return false;
//
//     }
// };
class Solution {
public:
    bool search(vector<int>& nums, int target) {
      int size = nums.size();
      int i = 0;
      int j = n-1;

      while(i <= j){
        mid = (i+j)/2;
        if(mid > nums[j]){
          if(target < mid && target >= nums[i]) j = mid;
          else i = mid+1;
        }
        else if(mid < nums[j]){
          if(mid < target && num[j] >= target) i = mid;
          else j = mid-1;
        }
        else
          j--;
      }
      return false;
    }
};
