class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> v1,v2;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(img1[i][j] == 1)
                    v1.push_back({i,j});
                if(img2[i][j] == 1)
                    v2.push_back({i,j});
            }
        }
            
        int count = 0;
        map<pair<int,int>, int> mp;
        for(auto i:v1) {
            for(auto j:v2) {
                pair<int,int> p = make_pair(j.first-i.first, j.second-i.second);
                if(mp.find(p) == mp.end()) {
                    mp[p] = 1;
                } else {
                    mp[p] += 1;
                }
                count = max(count, mp[p]);
            }
        }
        return count;
    }
};