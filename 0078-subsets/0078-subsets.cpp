class Solution {
public:
    void fun(int ind, vector<int> ds, vector<int> nums, vector<vector<int>> &ans) {
        if(ind == nums.size()) {
            ans.push_back(ds);
            return;
        }
        fun(ind+1, ds, nums, ans);
        ds.push_back(nums[ind]);
        fun(ind+1, ds, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        fun(0,ds,nums, ans);
        return ans;
    }
};