class Solution {
public:
    void findPermutations(int ind, vector<int> &nums, vector<vector<int>> &ans){
        if(ind == nums.size()) {
            ans.push_back(nums);
            return; 
        }
        for(int i=ind;i<nums.size();i++) {
            swap(nums[i], nums[ind]);
            findPermutations(ind+1, nums, ans);
            swap(nums[i], nums[ind]);
        }
    }
    
    // This works only when all the integers of nums array are unique.
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermutations(0, nums, ans);
        return ans;
    }
};