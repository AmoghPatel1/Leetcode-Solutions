class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();       
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) q.push({i,j});
            }
        }
        if(q.size() == 0 || q.size() == n*n) return -1;
        int dir [4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        int level = -1;    
        while(!q.empty()) {
            level+=1;
            int size = q.size();
            while(size-- > 0) {
                auto it = q.front();
                q.pop();
                
                for(int i=0;i<4;i++) {
                    int row = it.first + dir[i][0];
                    int col = it.second + dir[i][1];
                    if(row<0 || row>=n || col<0 || col>=n || grid[row][col] == 1) continue;
                    q.push({row,col});
                    grid[row][col] = 1;
                }
            }
        }
        
        return level;
    }
};