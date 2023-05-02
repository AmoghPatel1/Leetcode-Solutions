class Solution {
public:
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, 1, -1, 0};
    
    int bfs(int i, int j, vector<vector<int>> &grid, int m, int n) {        
        int fishes = grid[i][j];
        grid[i][j] = 0;

        for(int k=0;k<4;k++) {
            int x = i+dx[k], y = j+dy[k];
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y] > 0) {
                fishes += bfs(x, y, grid, m, n);
            }
        }
        return fishes;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] > 0) {
                    int maxm = bfs(i,j, grid, m, n);
                    ans = max(ans, maxm);
                }
            }
        }
        return ans;
    }
};