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
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return recursion(m-1,n-1, grid, dp);
    }
};