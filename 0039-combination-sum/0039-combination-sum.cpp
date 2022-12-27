class Solution {
public:
    // int count = 0;
    void f(vector<vector<int>> &v, int index, vector<int> &ds, vector<int> &candidates, int target) {
        // for(int i=0;i<ds.size();i++) cout << ++count << " ";
        cout << endl;
        if(index == candidates.size()) {
            if(target == 0) {
                v.push_back(ds);
            }
            return;
        }
        if(candidates[index] <= target) {
            ds.push_back(candidates[index]);
            f(v, index, ds, candidates, target-candidates[index]);
            ds.pop_back();
        }
        f(v, index+1, ds, candidates, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> ds;
        f(v, 0, ds, candidates, target);
        return v;
    }
};