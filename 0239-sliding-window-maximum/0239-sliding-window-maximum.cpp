class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> v;
        for(int i=0;i<k-1;i++) {
            s.insert(nums[i]);
        }
        for(int i=k-1;i<nums.size();i++) {
            s.insert(nums[i]);
            cout << *s.rbegin() << endl;
            v.push_back(*s.rbegin());
            s.erase(s.lower_bound(nums[i-k+1]));
        }
        return v;
    }
};