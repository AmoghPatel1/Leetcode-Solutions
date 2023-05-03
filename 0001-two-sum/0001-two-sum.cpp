class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr(2);
        int n = nums.size();
        map<int, int> mp;
        for(int i=0;i<n;i++) {
            mp[nums[i]] = i;
        }
        for(int i=0;i<n;i++) {
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end() && mp[rem] != i) {
                arr[0] = i;
                arr[1] = mp[rem];
            }
        }
        return arr;
    }
};