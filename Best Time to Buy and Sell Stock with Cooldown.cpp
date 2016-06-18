class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n ==1)
            return 0;
        vector<int> sell(n, 0);// sell [i] means the max profit we can get if we sell at day i+1;
        vector<int> buy(n, 0);// buy means max profit we can get if we buy stock at day i+1
        
        // for the first day
        sell[0] = 0;
        buy[0] = -prices[0];
        
        int max_profit = 0;
        
        // form the second day to nthday
        for(int i = 1 ; i < n ; i++){
            sell[i] = max(buy[i-1] + prices[i], sell[i-1] + prices[i] - prices[i-1]);
            //buy[i-1] + prices[i] means buy stock at the ith day and sell it at i+1 day;
            //sell[i-1] + prices[i] - prices[i-1]  means we will not sell the stock at ith day but at i+1day
            if(sell[i] > max_profit) max_profit = sell[i];
            
            if(i == 1)
                buy[i] = buy[i-1] + prices[i-1] - prices[i];
            // in the first day we cannot sell the stock so the buying will not be blocked if we dont buy in the first day
            
            else buy[i] =max(buy[i-1] + prices[i-1] - prices[i], sell[i-2] - prices[i]);
            //buy[i-1] + prices[i-1] - prices[i] means we will not buy on the ith day but buy on i+1th day;
            //sell[i-2] - prices[i] means if we have already selled in i-1 day so we cannot buy on ith day;
            
        }
        
        return max_profit;
        
        
    }
};