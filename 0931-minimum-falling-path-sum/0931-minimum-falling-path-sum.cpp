class Solution {
public:
//     int recursion(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
//         if(row == matrix.size()-1) return matrix[row][col];
//         if(dp[row][col] != -1) return dp[row][col];
//         int down = matrix[row][col] + recursion(row+1, col, matrix, dp);
//         int downLeft = INT_MAX, downRight = INT_MAX;
//         if(col>0) downLeft = matrix[row][col] + recursion(row+1, col-1, matrix, dp);
//         if(col<matrix.size()-1) downRight = matrix[row][col] + recursion(row+1, col+1, matrix, dp);
//         return dp[row][col] = min(min(down, downLeft), min(down, downRight));
        
//     }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);
        int ans = INT_MAX;
        for(int i=n-1;i>=0;i--) {
            prev[i] = matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--) {
            vector<int> cur(n,0);
            for(int j=n-1;j>=0;j--) {
                int down = matrix[i][j] + prev[j];
                int downLeft = INT_MAX, downRight = INT_MAX;
                if(j>0) downLeft = matrix[i][j] + prev[j-1];
                if(j<n-1) downRight = matrix[i][j] + prev[j+1];
                cur[j] = min(min(down, downLeft), min(down, downRight));
            }
            prev = cur;
        }
        for(int i=0;i<n;i++) {
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};