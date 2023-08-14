class Solution {
public:
    int bfs(vector<vector<pair<int,int>>> &adj) {
        vector<bool> vis(adj.size(), false);
        int ans = INT_MAX;
        queue<int> q;
        q.push(1);
        vis[1] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++) {
                ans = min(ans, adj[node][i].second);
                if(!vis[adj[node][i].first]) {
                    vis[adj[node][i].first] = true;
                    q.push(adj[node][i].first);
                }   
            }
        }
        return ans;
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        int size = roads.size();
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<size;i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        return bfs(adj);
    }
};  