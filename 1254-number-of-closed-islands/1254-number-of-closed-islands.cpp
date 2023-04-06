class Solution {
public:
    
    bool isValid(int i, int j, int n, int m, vector<vector<int>> &grid) {
        if(i < n && i >=0 && j < m && j>=0 && grid[i][j] == 0) return true;
        return false;
    }
    
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid) {
        grid[i][j] = 1;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        for(int k=0;k<4;k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if(isValid(nx, ny, n, m, grid)) {
                dfs(nx, ny, n, m, grid);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        for(int i=0;i<n;i++ ){
            for(int j=0;j<m;j++) {
                if(i*j==0 || i==n-1 || j==m-1) {                        // boundary condition
                    // cout << i << " " << j << endl;
                    if(grid[i][j] == 0) {
                        dfs(i, j, n, m, grid);
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++ ){
            for(int j=0;j<m;j++) {
                // cout << i << " " << j << endl;
                if(grid[i][j] == 0) {
                    ans+=1;
                    dfs(i, j, n, m, grid);
                }
            }
        }   
        
        return ans;
    }
};