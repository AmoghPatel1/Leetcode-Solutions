#define pv(v) {for(int i=0;i<v.size();i++) {cout << v[i] << " ";}cout << endl;}
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if(target > sum) {
            ans += (target/sum) * n;
            target %= sum;
        }
        nums.insert(nums.end(), nums.begin(), nums.end());
        // cout << target << endl;
        int count = INT_MAX;
        int left = 0, right = 0;
        long long cur = 0;
        while(right < nums.size()) {
            if(cur == target) count = min(count, right-left);
            cur += nums[right];
            // cout << left << " " << right << " " << cur << endl;
            while(cur > target) {
                cur -= nums[left];
                left += 1;
            }
            // cout << count << endl;
            right += 1;
        }
        return count != INT_MAX ? ans + count : -1;
    }
};