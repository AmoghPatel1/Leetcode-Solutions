class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) v.push_back(i);
        }
        if(v.size() == 0) return n-1;
        int prev = -1, ans = 0;
        for(int i=0;i<v.size();i++) {
            if(i == v.size()-1) {
                ans = max(ans, v[i]-prev-1 + n - v[i] - 1);
            } else {
                ans = max(ans, v[i+1] - prev - 2);
                prev = v[i];
            }
        }
        return ans;
    }
};  