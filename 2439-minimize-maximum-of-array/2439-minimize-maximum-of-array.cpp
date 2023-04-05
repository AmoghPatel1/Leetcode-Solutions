class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long sum = nums[0];
        int ans = nums[0];
        int maxm;
        for(int i=1;i<n;i++) {
            sum += nums[i];
            // cout << sum << " " << (i+1) << endl;
            maxm = sum%(i+1)==0 ? sum/(i+1):sum/(i+1) +1;
            // cout << maxm << endl;
            ans = max(ans, maxm);
        }
        return ans;
    }
};