class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            mp[nums[i]] += 1;
        }

        // for(auto it: mp) {
        //     cout << it.first << " " << it.second << endl;
        // }
        // cout << endl;

        int ans = 0;
        for(int i=0;i<n;i++) {
            // cout << nums[i] << endl;
            if(mp.count(nums[i])) {
                if(mp[nums[i]] > 1) mp[nums[i]] -= 1;
                else mp.erase(nums[i]);
            } else continue;
            int comp = k - nums[i];
            if(mp.count(comp)) {
                ans += 1;
                if(mp[comp] > 1) mp[comp] -= 1;
                else mp.erase(comp);
            }
            // for(auto it: mp) {
            //     cout << it.first << " " << it.second << endl;
            // }
            // cout << ans << endl;
            // cout << endl;
        }
        return ans;
    }
};