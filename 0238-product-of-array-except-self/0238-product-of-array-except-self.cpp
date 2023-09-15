class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZeroes = 0;
        int product = 1;
        int n = nums.size();
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) countZeroes += 1;
            else {
                product *= nums[i];
            }
        }
        if(countZeroes > 1) {
            vector<int> ans(n,0);
            return ans;
        } else if(countZeroes == 1) {
            vector<int> ans(n,0);
            for(int i=0;i<n;i++) {
                if(nums[i] == 0) ans[i] = product;
            }
            return ans;
        } else {
            vector<int> ans(n);
            for(int i=0;i<n;i++) {
                ans[i] = product/nums[i];
            }
            return ans;
        }
    }
};