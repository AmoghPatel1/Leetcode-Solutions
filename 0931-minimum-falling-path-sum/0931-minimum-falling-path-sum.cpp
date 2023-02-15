class Solution {
public:
    int recursion(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(row == matrix.size()-1) return matrix[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        int down = matrix[row][col] + recursion(row+1, col, matrix, dp);
        int downLeft = INT_MAX, downRight = INT_MAX;
        if(col>0) downLeft = matrix[row][col] + recursion(row+1, col-1, matrix, dp);
        if(col<matrix.size()-1) downRight = matrix[row][col] + recursion(row+1, col+1, matrix, dp);
        return dp[row][col] = min(min(down, downLeft), min(down, downRight));
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int ans = INT_MAX;
        for(int i=0;i<n;i++) {
            ans = min(ans, recursion(0, i, matrix, dp));
        }
        return ans;
    }
};