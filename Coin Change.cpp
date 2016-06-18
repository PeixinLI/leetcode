class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();
        if(N == 0) return 0;
        vector<int> nums(amount,-1);
        for(int i = 0; i < N; i++){
            if(coins[i] <= amount)
                nums[coins[i] -1] = 1;
        }
        for(int i = coins[0]+1; i < amount; i++){
            for(int j = 0; j < N ;j++){
                if(coins[j] >= i) break;
                if(nums[i] == -1) nums[i] = nums[i - coins[j]] +1;
                else if(nums[i - coins[j]] != -1 && nums[i] > (nums[i - coins[j]] + 1))
                    nums[i] = nums[i - coins[j]];
            }
        }
        
        return nums[anount -1];
        
    }
};