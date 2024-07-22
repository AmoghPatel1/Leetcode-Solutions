class Solution {
public:
    bool isPal(string s) {
        int n = s.size();
        for(int i=0;i<n;i++) {
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }

    void fun(int x, string s, vector<string> v, vector<vector<string>> &ans) {
        if(x == s.size()) {
            ans.push_back(v);
            return;
        }

        int n = s.size();
        string t = "";
        for(int i=x;i<n;i++) {
            t += s[i];
            if(isPal(t)) {
                v.push_back(t);
                fun(i+1, s, v, ans);
                v.pop_back();
            }
            
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        fun(0, s, {}, ans);
        return ans;
    }
};