class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(auto it:nums) sum += it;
        if(sum < target) return 0;
        else if(sum == target) return n;
        else {
            int i=0, j=0, ans=INT_MAX; sum=0;
            while(i<n && j<n) {
                while(j<n && sum<target) {
                    sum += nums[j];
                    j+=1;
                }
                while(i<n && sum >= target) {
                    ans = min(ans, j-i);
                    sum -= nums[i++];
                }
            }
            return ans;
        }
        
    }
};