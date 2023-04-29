//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void dfs(int i, int j, vector<vector<char>> &grid, int n, int m) {
        grid[i][j] = '0';
        int p=i-1, q=j-1;
        if(p>=0 && p<n && q>=0 && q<m && grid[p][q] == '1')
            dfs(p, q, grid, n, m);
        p=i-1, q=j;
        if(p>=0 && p<n && q>=0 && q<m && grid[p][q] == '1')
            dfs(p, q, grid, n, m);
        p=i-1, q=j+1;
        if(p>=0 && p<n && q>=0 && q<m && grid[p][q] == '1')
            dfs(p, q, grid, n, m);
        p=i, q=j-1;
        if(p>=0 && p<n && q>=0 && q<m && grid[p][q] == '1')
            dfs(p, q, grid, n, m);
        p=i, q=j+1;
        if(p>=0 && p<n && q>=0 && q<m && grid[p][q] == '1')
            dfs(p, q, grid, n, m);
        p=i+1, q=j-1;
        if(p>=0 && p<n && q>=0 && q<m && grid[p][q] == '1')
            dfs(p, q, grid, n, m);
        p=i+1, q=j;
        if(p>=0 && p<n && q>=0 && q<m && grid[p][q] == '1')
            dfs(p, q, grid, n, m);
        p=i+1, q=j+1;
        if(p>=0 && p<n && q>=0 && q<m && grid[p][q] == '1')
            dfs(p, q, grid, n, m);
        
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    count += 1;
                    dfs(i, j, grid, n, m);
                }
            }
        }
        // Code here
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends