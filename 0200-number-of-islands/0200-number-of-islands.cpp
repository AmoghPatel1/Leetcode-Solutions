class Solution {
public:
    int difX[4] = {-1,0,0,1};
    int difY[4] = {0,-1,1,0};

    void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &vis) {
        vis[x][y] = true;
        int m = grid.size(), n = grid[0].size();

        for(int i=0;i<4;i++) {
            int newX = x + difX[i], newY = y + difY[i];
            if(newX<m && newX >= 0 && newY<n && newY >=0 && grid[newX][newY] == '1' && !vis[newX][newY]) {
                dfs(newX, newY, grid, vis);
            }
        }
    }   

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool> (n,false));
        int noOfIslands = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    noOfIslands += 1;
                    dfs(i,j,grid, vis);
                }
            }
        }
        return noOfIslands;
    }
};