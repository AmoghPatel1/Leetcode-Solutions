class Solution {
public:
    void recurse(int ind, vector<int> ds, vector<int>& candidates, int target, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++) {
            if(i>ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            recurse(i+1, ds, candidates, target-candidates[i], ans); // Why i+1? because we took 'i' index and each index can only be taken once.
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        // set<vector<int>> s;
        sort(candidates.begin(), candidates.end());      
        int n = candidates.size();
        recurse(0, {}, candidates, target, ans);
        // for(auto it: s) ans.push_back(it);
        return ans;
    }
};