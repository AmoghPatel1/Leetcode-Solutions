class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int i=0;
        while(i<nums.size()) {
            if(i+1<nums.size()) {
                if(i+1<nums.size() && nums[i] == nums[i+1]) {
                    if(count == 2) {
                        while(i+1 < nums.size() && nums[i] == nums[i+1])
                            nums.erase(nums.begin()+i+1);
                        count = 1;
                    } else count += 1;
                
                } else if(nums[i] != nums[i+1]) 
                    count = 1;
            }  
            i+=1;
        }
        return nums.size();
    }
};