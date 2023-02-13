class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n,0);
        for(int i=0;i<m;i++) {
            vector<int> cur(n,0);
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) cur[j]=0;
                else if(i==0&&j==0) cur[j]=1;
                else {
                    int up=0,left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=cur[j-1];
                    cur[j] = up+left;
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};
