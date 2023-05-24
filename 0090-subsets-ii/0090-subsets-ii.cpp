class Solution {
public:
    void fun(int index, vector<int> nums, vector<int> v, set<vector<int>> &s) {
        if(index == nums.size()) {
            s.insert(v);   
            return;
        }
        fun(index+1, nums, v, s);
        v.push_back(nums[index]);
        fun(index+1, nums, v, s);    
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;\
        sort(nums.begin(), nums.end());
        fun(0, nums, {}, s);
        vector<vector<int>> ans;
        for(auto it: s) ans.push_back(it);
        return ans; 
    }
};