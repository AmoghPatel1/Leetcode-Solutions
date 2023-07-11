class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto it : nums) {
            mp[it] += 1;
        }
        // for(auto it : mp) {
        //     cout << it.first << " " << it.second << endl;
        // }
        vector<pair<int,int>> vp;
        vector<int> ans;
        for(auto it: mp) vp.push_back(it);
        sort(vp.begin(), vp.end(), [](pair<int,int> &a, pair<int,int> &b) {
            return a.second > b.second;
        });
        if(k > vp.size()) return {};
        int freq = vp[k-1].second;
        for(auto it: vp) {
            if(it.second >= freq) ans.push_back(it.first);
        }
        return ans;
    }
};