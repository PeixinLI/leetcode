
// O(n) Solution
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return 0;
        vector<int> sum(N+1, 0);
        int begin = 0;
        int end = 1;
        int minLen = N+1;
        
        for(int i = 1; i <= N; i++)
            sum[i] = sum[i-1] + nums[i-1];
        //cout<<sum[i]<<endl;
        
        
        while(end < N){ // if the sum is smaller than s then move end backwards
            if((sum[end] - sum[begin]) < s) end++;
            while((begin < end) && (sum[end] - sum[begin]) >= s){
                //cout<<sum[end]<< " "<<sum[begin]<<endl;
                if((end - begin ) < minLen)
                    minLen = end - begin;
                begin ++;
            }
            
        }
        
        if(minLen == N+1)
            return 0;
        else
            return minLen;
        
        
    }
};