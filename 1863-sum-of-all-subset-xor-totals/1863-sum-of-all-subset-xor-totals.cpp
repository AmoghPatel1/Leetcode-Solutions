class Solution {
public:
    int f(int ind, int var, vector<int> &nums) {
        if(ind == nums.size()){
            return var;
        }
        int pick = f(ind+1, var^nums[ind], nums);
        int notPick = f(ind+1, var, nums);
        return pick+notPick;
    }
    int subsetXORSum(vector<int>& nums) {
        return f(0, 0, nums);
    }
};