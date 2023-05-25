class Solution {
public:
//     void fun(int index, vector<int> nums, vector<int> v, vector<vector<int>> &ans) {
//         ans.push_back(v);
        
//         for(int i=index;i<nums.size();i++) {
//             if(i>index && nums[i] == nums[i-1]) continue;
//             v.push_back(nums[i]);
//             fun(i+1, nums, v, ans);
//             v.pop_back();
//         }
//     }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> results;

        function<void(int, vector<int>)> recurse = [&](int index, vector<int> subset) {
            results.push_back(subset);
            for(int i=index;i<nums.size();i++) {
                if(i>index && nums[i] == nums[i-1]) continue;
                subset.push_back(nums[i]);
                recurse(i+1, subset);
                subset.pop_back();
            } 
        };

        recurse(0, {});

        return results;
    }
};