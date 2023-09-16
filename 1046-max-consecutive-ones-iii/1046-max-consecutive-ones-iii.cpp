class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        int l = 0, r = 0;
        while(r < n) {
            if(nums[r] == 0) k -= 1;
            while(k<0) {
                if(nums[l] == 0)
                    k += 1;
                l += 1;
            }
            ans = max(ans, r-l+1);            
            r += 1;
        }
        return ans;
    }
};