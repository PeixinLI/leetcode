//treeSum use the different solution od 2 sum because 2 sum uses hash table to search in O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        
        sort(nums.begin(), nums.end());
        nums.remove(unique(nums.begin, nums.end()), nums.end());//have duplicate num in this case
        int N = nums.size()
        for(int first = 0; first < N-2; first++){ // for the fixed first num
            int second = first +1;
            int third = N - 1;
            while(second < third){
                int sum = nums[first] + nums[second] + nums[third]
                if((sum < 0)
                    second++;
                else if(sum > 0)
                    third--;
                else if(sum == 0){
                    res.push_back({first, second, third});
                    second++;
                   }
            }
        }
        
                   
     return sum;
    }
};