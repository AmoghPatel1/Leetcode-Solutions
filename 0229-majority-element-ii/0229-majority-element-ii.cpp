class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int first = nums[0], second = INT_MAX;
        for(int i=0;i<n;i++) {
            if(nums[i] != first && second == INT_MAX) second = nums[i];
            if(nums[i] == first) cnt1 += 1;
            else if(nums[i] == second) cnt2 += 1;
            else if(cnt1 == 0) {
                first = nums[i];
                cnt1 = 1;
            } else if(cnt2 == 0) {
                second = nums[i];
                cnt2 = 1;
            } else {
                cnt1 -= 1;
                cnt2 -= 1;
            }
        }
        cnt1 = cnt2 = 0;
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(nums[i] == first) cnt1 += 1;
            else if(nums[i] == second) cnt2 += 1;
        }
        if(cnt1 > n/3) ans.push_back(first);
        if(cnt2 > n/3) ans.push_back(second);
        return ans;
    }
};