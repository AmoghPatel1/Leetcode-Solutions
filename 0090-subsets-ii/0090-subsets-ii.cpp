class Solution {
public:
    void fun(int ind, vector<int> ds, vector<int> nums, vector<vector<int>> &ans) {
        ans.push_back(ds);
        // fun(ind+1, ds, nums, ans);
        // ds.push_back(nums[ind]);
        // fun(ind+1, ds, nums, ans);
        for(int i=ind;i<nums.size();i++) {
            if(i>ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            fun(i+1, ds, nums, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        fun(0,ds,nums,ans);
        return ans;
    }
};