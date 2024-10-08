class Solution {
public:
    void dfs(int node, vector<vector<int>> adj, vector<int>& visited) {
        visited[node] = 1;
        for(int i=0;i<adj[node].size();i++) {
            if(!visited[adj[node][i]]) 
                dfs(adj[node][i], adj, visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                } 
            }
        }
        int ans = 0;
        vector<int> visited(n, 0);
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(i, adj, visited);
                ans += 1;
            }
        }
        return ans;
    }
};