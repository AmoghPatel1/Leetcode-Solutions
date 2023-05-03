class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++) {
            int low = i+1, high = n-1;
            // int target = (-1)*(nums[i] + nums[j]);
            while(low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if(sum == 0){
                    s.insert({nums[i],nums[low],nums[high]});
                    low += 1;
                    high -= 1;
                } else if(sum < 0) {
                    low += 1;
                } else {
                    high -= 1;
                }
            }
        }
        for(auto it: s)
            ans.push_back(it);
        return ans;
    }
};