class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm = INT_MAX;
        int profit = 0;
        for(int i=0;i<prices.size();i++) {
            if(prices[i] < minm) minm = prices[i];
            else if(prices[i] - minm > profit)
                profit = prices[i] - minm;
        }
        return profit;
    }
};