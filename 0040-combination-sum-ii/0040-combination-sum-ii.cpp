class Solution {
public:
    void findCombination(int ind, vector<int> &ds, vector<int> &candidates, int target, vector<vector<int>> &ans) {
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++) {
            if(i>ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            findCombination(i+1, ds, candidates, target-candidates[i], ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, ds, candidates, target, ans);
        return ans;
    }
};