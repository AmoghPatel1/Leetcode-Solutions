class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        set<int> s;
        int n1 = nums1.size(), n2 = nums2.size();
        set<int> s1,s2;
        for(int i=0;i<n1;i++) s1.insert(nums1[i]);
        for(int i=0;i<n2;i++) s2.insert(nums2[i]);
        for(int i=0;i<n1;i++) {
            if(!s2.count(nums1[i])) s.insert(nums1[i]);
        }
        vector<int> v;
        for(auto it: s) v.push_back(it);
        ans.push_back(v);
        v.clear(); s.clear();
        for(int i=0;i<n2;i++) {
            if(!s1.count(nums2[i])) s.insert(nums2[i]);
        }
        for(auto it: s) v.push_back(it);
        ans.push_back(v);
        return ans;
    }
};