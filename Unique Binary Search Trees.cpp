class Solution {
public:
    int numTrees(int n) {
        vector<int> nums;
        if(n == 0) return 0;
        nums.push(1);
        
        for(int i = 1; i < n; i++){
            int t = 0;
            for(int j = 0; j < i; j++)
                t += nums[j] * nums[i - j -1];
            return t;
        }
        return nums[n-1];
        
    }
};