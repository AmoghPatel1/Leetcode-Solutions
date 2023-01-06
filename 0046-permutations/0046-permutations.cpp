class Solution {
public:
    void findPermutations(vector<int> &nums, vector<int> &ds, vector<bool> &freq, vector<vector<int>> &ans){
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return; 
        }
        for(int i=0;i<nums.size();i++) {
            if(!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = true;
                findPermutations(nums, ds, freq, ans);
                ds.pop_back();
                freq[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> freq(nums.size(), false);
        findPermutations(nums, ds, freq, ans);
        return ans;
    }
};