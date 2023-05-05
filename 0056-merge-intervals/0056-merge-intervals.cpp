class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int i=0;
        while(i<n){
            int j = 1, second = intervals[i][1], first = intervals[i][0];
            while(i+j<n && intervals[i+j][0] <= second) {
                second = max(second, intervals[i+j][1]);
                first = min(first, intervals[i+j][0]);
                j+=1;
            }
            ans.push_back({first, second});
            i+=j;
        }
        return ans;
    }
};