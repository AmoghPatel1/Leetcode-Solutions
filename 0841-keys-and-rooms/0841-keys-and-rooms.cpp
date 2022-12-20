class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visited(n,0);
        queue<int> q;
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int i=q.front();q.pop();
            // cout<<i<<endl;
            for(auto j:rooms[i]){
                if(visited[j]==0){
                    q.push(j);
                    visited[j]=1;
                }
            }
        }
        sort(visited.begin(),visited.end());
        return visited[0]==0?false:true;

    }
};