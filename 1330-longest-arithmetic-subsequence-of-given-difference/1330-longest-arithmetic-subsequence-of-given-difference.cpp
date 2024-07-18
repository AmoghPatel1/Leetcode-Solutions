class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        unordered_map<int,int> mp;
        int ans = 1;
        for(int i=0;i<n;i++) {
            mp[arr[i]] = 1+mp[arr[i] - difference];
        }
        for(int i=0;i<n;i++) {
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }
};