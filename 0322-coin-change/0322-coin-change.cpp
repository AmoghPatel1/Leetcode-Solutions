class Solution {

#define INF 1e5
    
public:
    int recurse(int amount, vector<int>&coins, vector<int> &dp) {
        if(amount == 0) return 0;
        
        if(dp[amount] != -1) return dp[amount];
        
        int ans = INF;
        for(int i=0;i<coins.size();i++) {
            int dif = amount - coins[i];
            if(dif >= 0) {
                int subAns = 0;
                
                if(dp[dif] != -1)
                    subAns = dp[dif];
                else
                    subAns = recurse(dif, coins, dp);
                
                if(subAns != INF && subAns+1 < ans){    
                    ans = subAns + 1;
                }
            }
        }
        
        return dp[amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        int ans = recurse(amount, coins, dp);
        return ans == INF ? -1 : ans;
    }
};