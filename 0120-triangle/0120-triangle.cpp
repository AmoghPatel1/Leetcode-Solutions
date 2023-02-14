class Solution {
public:
    int recursion(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(row == triangle.size()-1) return triangle[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        int down = triangle[row][col] + recursion(row+1, col, triangle, dp);
        int diagonal = triangle[row][col] + recursion(row+1, col+1, triangle, dp);
        return dp[row][col] = min(down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return recursion(0, 0, triangle, dp);
    }
};