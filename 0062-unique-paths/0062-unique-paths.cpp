class Solution {
public:
    
//     int recursion(int row, int col, vector<vector<int>> &dp) {
//         if(row == 0 && col == 0)
//             return 1;
//         if(row < 0 || col < 0)
//             return 0;
//         if(dp[row][col] != -1) return dp[row][col];
//         int up = recursion(row-1, col, dp);
//         int left = recursion(row, col-1, dp);
        
//         return dp[row][col] = up + left;
//     }
    
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++) {
            vector<int> temp(n,0);
            for(int j=0;j<n;j++) {
                int up = 0, left = 0;
                if(i>0) up = dp[j];
                if(j>0) left = temp[j-1];
                temp[j] = up + left;
            }
            dp = temp;
        }
        return dp[n-1];
    }
};