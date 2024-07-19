class Solution {
public:
    int fun(int x, vector<int>& coins, int amount, vector<vector<int>> &dp) {
        if(amount < 0 || x < 0) return 1e9;
        if(x == 0 && amount%coins[x] == 0) return amount/coins[x];

        if(dp[x][amount] != -1) return dp[x][amount];
        // not pick 
        int notPick = fun(x-1, coins, amount, dp);

        // pick
        int pick = 1e9;
        if(coins[x] <= amount) {
            pick = 1 + fun(x, coins, amount-coins[x], dp);
        }
        
        return dp[x][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = fun(n-1, coins, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};