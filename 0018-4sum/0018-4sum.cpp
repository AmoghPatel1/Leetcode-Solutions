class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int left = j+1, right = n-1;
                while(left < right) {
                    long long sum = (long long) nums[i] +  (long long) nums[j] +  (long long) nums[left] +  (long long) nums[right];
                    if(sum < target) {
                        left += 1;
                    } else if(sum > target) {
                        right -= 1;
                    } else {
                        st.insert({nums[i], nums[j], nums[left], nums[right]});
                        left += 1;
                        right -= 1;
                    }
                }
            }
        }
        for(auto it: st) ans.push_back(it);
        return ans;
    }
};