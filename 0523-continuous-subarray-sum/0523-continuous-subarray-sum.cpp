class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp {{0,0}};   // Map contains index of remainder. 
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            if(!mp.count(sum%k))        // If unique remainder comes then add it in map.
                mp[sum%k] = i+1;
            else if (mp[sum%k] < i)         
                return true;
        }
        return false;
    }
};