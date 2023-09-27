class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for(int i=1;i<m-1;i++) {
            for(int j=1;j<n-1;j++) {
                int sum = grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1]+grid[i][j]+grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};