class Solution {
public:
    int rob(vector<int>& nums) {
        int L = nums.size();
        if(L == 0) return 0;
        if(L == 1) return nums[0];
        
        int* M = new int[L];
        M[0] = nums[0];
        M[1] = Max(nums[0], nums[1]);
        
        for(int i = 2; i < L ; i++){
            M[i] = Max(M[i-1], M[i-2]+nums[i]);
        }
        
        return M[L-1];
        
    }
    int Max(int a ,int b){
        return a>b? a:b;
    }
};

