class Solution {
public:
    int numDecodings(string s) {
        int N = s.size();
        if(N == 0) return 0;
        if(N == 1) return 1;
        vector<int> dways(N + 1);
        dways[0] = 1;
        dways[1] = 1;
        for(int i = 2; i <= N; i++){
            int temp = s[i-1] - '0';
            temp = temp*10 + s[i]- '0';
            if(temp <= 26) dways[i] = dways[i-1] + dways[i-2];
            else dways[i] = dways[i-1];
        }
        
        return dways[N];
    }
};