class Solution {
public:
    int recursion(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(row == 0 && col == 0) return grid[0][0];
        if(row < 0 && col < 0) return INT_MAX;
        if(dp[row][col] != -1) return dp[row][col];
        int up = INT_MAX, left = INT_MAX;
        if(row > 0) up = grid[row][col] + recursion(row-1, col, grid, dp);
        if(col > 0) left = grid[row][col] + recursion(row, col-1, grid, dp);
        return dp[row][col] = min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int> (n, 0));
        // return recursion(m-1, n-1, grid, dp);
        vector<int> prev(n, 0);
        for(int i=0;i<m;i++){
            vector<int> cur(n,0);
            for(int j=0;j<n;j++) {
                if(i==0 && j==0) cur[j] = grid[0][0];
                else {
                    int up = INT_MAX, left = INT_MAX;
                    if(i>0) up = grid[i][j] + prev[j];
                    if(j>0) left = grid[i][j] + cur[j-1];
                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[n-1];
        
    }
};