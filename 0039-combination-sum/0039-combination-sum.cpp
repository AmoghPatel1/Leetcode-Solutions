class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        int n = candidates.size();
        function<void(int, int, vector<int>)> recurse = [&] (int ind, int sum, vector<int> comb) {
            if(ind >= n || sum >= target) {
                if(sum == target) {
                    ans.push_back(comb);
                } 
                return;
            }
            recurse(ind+1, sum, comb);
            sum += candidates[ind];
            comb.push_back(candidates[ind]);
            recurse(ind, sum, comb);      
        };
        recurse(0, 0, {});
        return ans;
    }
};