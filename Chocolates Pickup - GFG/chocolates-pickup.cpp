//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int recursion(int row, int col1, int col2, vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>>& dp) {
        if(col1<0 || col2<0 || col1>=m || col2>=m) return 1e-8;
        if(row == n-1){
            if(col1 == col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
        int mat[3] = {-1, 0, 1};
        int maxm = INT_MIN;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(col1 == col2) maxm = max(maxm, grid[row][col1] + recursion(row+1, col1+mat[i], col2+mat[j], grid, n, m, dp));
                else maxm = max(maxm, grid[row][col1] + grid[row][col2] + recursion(row+1, col1+mat[i], col2+mat[j], grid, n, m, dp));
            }
        }
        return dp[row][col1][col2] = maxm;
    }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp;
        dp.resize(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(m);
            for (int j = 0; j < m; j++) {
                dp[i][j].resize(m, -1);
            }
        }
        return recursion(0, 0, m-1, grid, n, m, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends