class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        map<int,int> mp;
        long long ans = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) {
                count+=1;
            } else {
                mp[count] += 1;
                count = 0;
            }
        }
        if(count > 0) {
            mp[count] += 1;
        }
        for(auto it: mp) {
            cout << it.first << " " << it.second << endl;
            long long k = it.first;
            ans += it.second*(k*(k+1)/2);
        }
        return ans;
    }
};