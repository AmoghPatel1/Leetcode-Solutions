class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            int comp = k - nums[i];
            if(mp.count(comp)) {
                ans += 1;
                if(mp[comp] > 1) mp[comp] -= 1;
                else mp.erase(comp);
            } else mp[nums[i]] += 1;
        }
        return ans;
    }
};