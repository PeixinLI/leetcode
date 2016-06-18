class Solution {
public:
    int rob(vector<int>& nums) {
        int L = nums.size();
        if(L == 0) return 0;
        if(L == 1) return nums[0];
        if(L == 2) return Max(nums[0], nums[1]);
        if(L == 3) {
            int temp = Max(nums[0], nums[1]);
            return Max(temp, nums[2]);
        }
        
        int* M = new int[L][2]; //0 for first 0
        M[0][0] = 0;
        M[0][1] = nums[0];
        M[1][0] = nums[1];
        M[1][1] = nums[0];
        
        for(int i = 2; i < L-1 ; i++){
            M[i][0] = Max(M[i-1][0], M[i-2][0] + nums[i]);
            M[i][1] = Max(M[i-1][1], M[i-2][1] + nums [i]);
        }
        
        M[L-1][0] = Max(M[L-2][0],M[L-3][0]+nums[L-1]);
        M[L-1][1] = M[L-2][1];
        
        return Max(M[L-1][0],M[L-1][1]);
        
        
    }
    int Max(int a ,int b){
        return a>b? a:b;
    }
};

