class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return 0;
        if(N == 1) return 1;
        vector<int> seq_l(N, 1);

        for(int i = 1; i < N; i++){
            for(int j = 0; j < N; j++){
                if(nums[j] < nums[i] && (seq_l[j] + 1) > seq_l[i])
                    seq_l[i] = seq_l[j] + 1;
            }
        }
        int max = 0;
        for(int i = 0; i < N;i++)
            if(max < seq_l[i]) max = seq_l[i];
        return max;
    }
};