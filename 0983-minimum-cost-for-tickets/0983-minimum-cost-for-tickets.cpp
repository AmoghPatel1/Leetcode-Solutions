class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> v(366, 0);
        set<int> s;
        for(int i=0;i<days.size();i++) {
            s.insert(days[i]);
        }
        vector<int> dp(366, 0);
        for(int i=1;i<=365;i++) {
            if(s.find(i) != s.end()) {
                dp[i] = min(min(dp[max(i-1,0)]+costs[0], dp[max(i-7,0)]+costs[1]), 
                            min(dp[max(i-7,0)]+costs[1], dp[max(i-30, 0)]+costs[2]));
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[365];
    }
};