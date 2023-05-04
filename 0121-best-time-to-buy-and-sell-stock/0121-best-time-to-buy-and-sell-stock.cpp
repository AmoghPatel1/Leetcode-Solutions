class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int profit = 0, minm = prices[0], n = prices.size();
        for(int i=0;i<prices.size();i++) {
            profit = max(profit, prices[i]-minm);
            minm = min(minm, prices[i]);
        }
        return profit;
    }
};