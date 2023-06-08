class Solution {
public:
    bool isPalindrome(string str) {
        int n = str.size();
        for(int i=0;i<n/2;i++) {
            if(str[i] != str[n-i-1]) return false;
        }
        cout << str << endl;
        return true;
    } 
    
    
    void recurse(int index, string s, vector<string> v, vector<vector<string>> &ans){
        if(index == s.size()) {
            ans.push_back(v);
            return;
        }
        for(int i=index+1;i<=s.size();i++) {
            string str = s.substr(index, i-index);
            if(isPalindrome(str)) {
                v.push_back(str);
                recurse(i, s, v, ans);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.size();
        recurse(0, s, {}, ans);
        return ans;
    }
};