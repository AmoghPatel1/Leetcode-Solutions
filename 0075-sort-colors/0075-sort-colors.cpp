class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) count0 += 1;
            if(nums[i] == 1) count1 += 1;
            if(nums[i] == 2) count2 += 1;
        }
        for(int i=0;i<count0;i++) {
            nums[i] = 0;
        }
        int ones = count0+count1;
        for(int i=count0;i<ones;i++) {
            nums[i] = 1;
        }
        int twos = nums.size();
        for(int i=ones;i<twos;i++) {
            nums[i] = 2;
        }
    }
};