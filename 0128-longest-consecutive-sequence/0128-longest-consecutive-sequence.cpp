class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int, int> mp;
        for(auto it : nums) mp[it] += 1;
        int ans = 1, prev = INT_MIN;
        int count = 1;
        for(auto it: mp) {
            if(prev != INT_MIN) {
                if(it.first == prev+1){
                    count += 1;
                } else count = 1;
                ans = max(ans, count);
                prev = it.first;
            }
            prev = it.first;
        }
        return ans;
    }
};