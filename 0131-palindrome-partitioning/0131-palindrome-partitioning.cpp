class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 1) return true;
        int n = s.size();
        for(int i=0;i<n/2;i++) {
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    
    void func(int ind, string s, vector<string> &ds, vector<vector<string>> &ans) {
        if(ind == s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++) {
            string str = s.substr(ind, i-ind+1);
            if(isPalindrome(str)){
                ds.push_back(s.substr(ind, i-ind+1));
                func(i+1, s, ds, ans);
                ds.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> ds;
        func(0, s, ds, ans);
        return ans;
    }
};