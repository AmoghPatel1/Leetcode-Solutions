class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++) {
            v.push_back({plantTime[i], growTime[i]});
        }
        sort(v.begin(),v.end(), comp);
        // for(auto it:v) {
        //     cout << it.first << " " << it.second << endl;
        // }
        int maxi = 0, cur = 0;
        for(auto it:v) {
            cur += it.first;
            maxi = max( maxi, cur + it.second);
        }
        
        return maxi;
    }
};