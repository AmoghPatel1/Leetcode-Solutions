class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        stack<int> s;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<k-1;i++) {
            if(i == 0) {
                s.push(nums[i]);
                continue;
            }
            int top = s.top();
            if(nums[i] - top == 1) {
                s.push(nums[i]);
            } else {
                while(s.size() != 0) {
                    s.pop();
                }
                s.push(nums[i]);
            }
        }
        for(int i=k-1;i<n;i++) {
            int top = s.top();
            if(nums[i] - top == 1) {
                s.push(nums[i]);
                if(s.size() >= k) {
                    ans.push_back(nums[i]);
                } else
                    ans.push_back(-1);
            } else {
                while(s.size() != 0) {
                    s.pop();
                }
                s.push(nums[i]);
                ans.push_back(-1);
            }
        }
        return ans;
    }
};