class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        for(auto num : nums) {
            if(cur < 2 || num > nums[cur-2]) {
                nums[cur++] = num;
            }
        }
        return cur;
    }
};