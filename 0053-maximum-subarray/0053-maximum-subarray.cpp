class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0], sum = nums[0];
        
        for(int i=1;i<n;i++) {
            if(sum < 0) sum = nums[i];
            else sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};