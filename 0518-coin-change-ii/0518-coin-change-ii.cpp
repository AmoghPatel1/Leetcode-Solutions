class Solution {

public:    
    int recurse(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if(ind == 0) return !(amount % coins[0]);
        int take = 0, notTake = 0;
        if(coins[ind] <= amount) {
            if(dp[ind][amount-coins[ind]] != -1) take = dp[ind][amount-coins[ind]]; 
            else take = recurse(ind, amount - coins[ind], coins, dp);
        }
            
        notTake = recurse(ind-1, amount, coins, dp);
        return dp[ind][amount] = take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for(int i=0;i<=amount;i++) {
            dp[0][i] = i%coins[0] == 0; 
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<=amount;j++) {
                int notTake = dp[i-1][j];
                int take = 0;
                if(coins[i] <= j) {
                    take = dp[i][j-coins[i]]; 
                }
                dp[i][j] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};