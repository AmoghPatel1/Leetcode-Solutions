class Solution {
public:
    int recursion(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if(row == 0 && col == 0 && grid[row][col] != 1) return 1;
        if(row<0 || col<0) return 0;
        if(grid[row][col] == 1) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int up = recursion(row-1, col, grid, dp);
        int left = recursion(row, col-1, grid, dp);
        return dp[row][col] = up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0 && j==0 && grid[i][j] != 1) dp[i][j] = 1;
                else {
                    int up = 0, left = 0;
                    if(i>0 && grid[i-1][j] != 1) up = dp[i-1][j];
                    if(j>0 && grid[i][j-1] != 1) left = dp[i][j-1];
                    if(grid[i][j] != 1) dp[i][j] = up + left;
                    else grid[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};