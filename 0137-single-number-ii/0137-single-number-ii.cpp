class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<=31;i++) {
            int sum = 0;
            for(int num : nums) {
                if(num>>i & 1) sum += 1;
            }
            if(sum%3 == 1) {
                ans |= 1<<i;
            }
        }
        return ans;
    }
};