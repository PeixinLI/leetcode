class Solution {
public:
    int numSquares(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> min_num(n+1, 9999999);
        min_num[0] = 0;
        min_num[1] = 1;
        for(int i = 2; i <= n; i++) //calculate the perfect square numbers of 2 - n
            for(int j = 1; j < i; j++ ){
                if(j*j > i) break;
                else if((min_num[i-j*j] + 1)> min_num[i]) min_num[i] = min_num[i-j*j] + 1;
            }
        return min_num[n+1];
    }
};