class Solution {
public:
    // int binary_search(vector<int> &nums, int num){
    //     int left = 0, right = nums.size()-1;
    //     while(left <= right) {
    //         int mid = (left+right)/2;
    //         if(nums[mid] == num) return mid+1;
    //         else if(nums[mid] < num) left = mid+1;
    //         else right = mid-1;
    //     }
    //     return left;
    // }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++)
            nums[i] += nums[i-1];
        vector<int> v;
        for(int i=0;i<queries.size();i++) {
            // int index = binary_search(nums, queries[i]);
            int index = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            v.push_back(index);
        }
        return v;
    }
};