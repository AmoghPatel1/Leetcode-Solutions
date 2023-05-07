class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int> st;
        for(auto it : nums) st.insert(it);
        int ans = 1, prev = INT_MIN;
        int count = 1;
        for(auto it: st) {
            if(prev != INT_MIN) {
                if(it == prev+1){
                    count += 1;
                } else count = 1;
            }
            ans = max(ans, count);
            prev = it;
        }
        return ans;
    }
};