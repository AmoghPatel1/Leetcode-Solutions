class Solution {
public:
    void f(int ind, vector<int> &ds, vector<int> &nums, vector<vector<int>> &subsets) {
        if(ind == nums.size()){
            if(ds.size() == 0) return;
            subsets.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        f(ind+1, ds, nums, subsets);
        ds.pop_back();
        f(ind+1, ds, nums, subsets);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> subsets;
        f(0, ds, nums, subsets);
        int sum = 0;
        for(int i=0;i<subsets.size();i++) {
            int p = subsets[i][0];
            for(int j=1;j<subsets[i].size();j++) {
                p ^= subsets[i][j];
            }
            sum += p;
        }
        return sum;
    }
};