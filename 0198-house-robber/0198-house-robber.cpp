class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev = 0;
        for(int i=0;i<nums.size();i++) {
            int temp = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = temp;
        }
        return prev;
    }
};