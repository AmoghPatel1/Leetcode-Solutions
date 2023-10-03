class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int x: nums) mp[x] += 1;
        for(auto x: mp) 
            if(x.second > n/3)
                ans.push_back(x.first);

        return ans;
    }
};