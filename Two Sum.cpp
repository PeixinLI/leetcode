class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> num; // num and its index
        vector<int> res;
        int N = nums.size();
        for(int i = 0; i < N; i++){
            int temp = target - nums[i];// find if already have the number which add nums[i] = target
            if(num.find(temp) != num.end()){
                res.push_back(num[temp]);
                res.push_back(i+1);
                return res;
            }
            num.insert(pair<int, int> (nums[i], i+1));
        }
        return res;
    }
};