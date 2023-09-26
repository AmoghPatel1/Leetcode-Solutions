class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = nums[0]+nums[1]+nums[2];
        int minDif = INT_MAX;
        for(int i=0;i<n;i++) {
            int left = i+1, right = n-1;
            while(left < right) {
                int sum = nums[i]+nums[left]+nums[right];
                int dif = abs(sum - target);
                if(dif < minDif) {
                    minDif = dif;
                    closest = sum;
                }
                if(sum > target) right-=1;
                else left += 1;
            }
        }
        return closest;
    }
};