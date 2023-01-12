class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==2) return (nums[0]-1)*(nums[1]-1);
        int ind = max_element(nums.begin(),nums.end())-nums.begin();
        int max1 = nums[ind];
        nums[ind] = 0;
        int max2 = *max_element(nums.begin(), nums.end());
        return (max1-1)*(max2-1);
    }
};