class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9+7;
        sort(nums.begin(), nums.end());
        int power[n];
        power[0] = 1;
        for(int i=1;i<n;i++) {
            power[i] = (power[i-1]*2) % mod;
        }
        
        int ans = 0;
        int left = 0, right = n-1;
        
        while(left <= right) {
            if(nums[left] + nums[right] <= target) {
                ans += power[right-left];
                ans %= mod;
                left+=1;
            } else right-=1;
        }
        return ans;
    }
};