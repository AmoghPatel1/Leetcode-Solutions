class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(nums.size());
        for(int i=0;i<nums.size();i++) {
            v[nums[i]-1] += 1;
        }
        int a,b;
        for(int i=0;i<v.size();i++) {
            if(v[i] == 2) a=i+1;
            if(v[i] == 0) b=i+1;
        }
        vector<int> vm = {a,b};
        return vm;
    }
};