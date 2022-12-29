class Solution {
public:
    void fun(int ind, vector<int> ds, vector<int> nums, set<vector<int>> &ans) {
        if(ind == nums.size()) {
            ans.insert(ds);
            return;
        }
        fun(ind+1, ds, nums, ans);
        ds.push_back(nums[ind]);
        fun(ind+1, ds, nums, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> ds;
        fun(0,ds,nums,s);
        for(auto it:s) ans.push_back(it);
        return ans;
    }
};