class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = -1, count = 0;
        for(int i=0;i<nums.size();i++) {
            if(i==0) {
                element = nums[0];
                count += 1;
            } else {
                if(nums[i] == element) count+=1;
                else {
                    count-=1;
                    if(count==0) {
                        count += 1;
                        element = nums[i];
                    }
                }
            }
        }
        return element;
    }
};