#define pii pair<int,int>

class Compare {
public:
    bool operator()(pii &a, pii &b) {
        return a.second < b.second;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]] += 1;
        priority_queue<pii, vector<pii>, Compare> pq;
        for(pii it: mp) pq.push({it.first, it.second});
        vector<int> ans;
        for(int i=0;i<k;i++) {
            int val = pq.top().first;
            ans.push_back(val);
            pq.pop();
        }
        return ans;
    }
};