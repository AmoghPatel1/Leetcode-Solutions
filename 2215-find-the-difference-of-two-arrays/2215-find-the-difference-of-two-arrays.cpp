class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        map<int,int> mp1, mp2;
        for(int i=0;i<nums1.size();i++) {
            mp1[nums1[i]] += 1;
        }
        for(int i=0;i<nums2.size();i++) {
            mp2[nums2[i]] += 1;
        }
        vector<int> v;
        for(auto it: mp1){
            if(mp2.count(it.first) == 0) v.push_back(it.first);
        }
        ans.push_back(v);
        v.clear();
        for(auto it: mp2){
            if(mp1.count(it.first) == 0) v.push_back(it.first);
        }
        ans.push_back(v);
        return ans;
    }
};