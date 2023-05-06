class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(auto it: nums){
            mp[it] += 1;
        }
        vector<int> ans;
        for(auto it: mp) {
            if(it.second > n/3) ans.push_back(it.first);
        }
        return ans;
    }
};