/*class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();

        return reach(nums, 0, length - 1);
    }

    bool reach(vector<int>&nums, int index, int distance){
        int max_step = nums[index];

        if(max_step >= distance)
            return true;

        for(int i = 1; i <= max_step; i++){
            if(reach(nums, index+i, distance - i) == true)
                return true;
        }

        return false;
    }
};
// Naive Solution : Timee Limit Exceed 
*/

// Dynamic Programing Solution
/*class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        bool* reach = new bool[length];

        for(int i = 0; i < length; i++){
            reach[i] = false;
        }

        for(int i = length - 1; i >= 0; i--){
            if(nums[i] >= length - i -1){
                reach[i] = true;
                continue;
            }

            for(int j = 1; j <= nums[i]; j++){
                if(reach[i+j] == true){
                    reach[i] = true;
                    break;
                }
            }           
        }

        return reach[0];

    }
};*/


//Optimized DP Solution

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();

        int i = 0;
        int max_reach = 0;

        while(i <= max_reach && i < length){
            int reach = nums[i] + i;

            if(reach > max_reach) max_reach = reach;
            if(max_reach >= length - 1) return true;

            i++;
        }

        return false;

    }
};