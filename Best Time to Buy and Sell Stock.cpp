class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if(N == 0 || N == 1) return 0;
        int min_price = INT_MAX;
        int max_pro = 0
        for(int i = 0; i < N; i++){
            if(min_price > prices[i]) min_price = prices[i];
            if(max_pro < prices[i] - min_price) max_pro = prices[i] - min_price;
        }
        return max_pro;
    }
};