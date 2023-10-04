class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        map<char,int> mp;
        for(auto x : tasks) mp[x] += 1;

        for(auto x: mp) cout << x.first << " " << x.second <<endl;

        priority_queue<pair<int,int>> pq;
        for(auto x: mp) pq.push({x.second, x.first});
        int maxm = pq.top().first;
        int count = 0;
        while(!pq.empty() && pq.top().first == maxm) {
            count += 1;
            pq.pop();
        }
        int ans = (n+1)*(maxm-1)+count;
        return max(ans, size);
    }
};