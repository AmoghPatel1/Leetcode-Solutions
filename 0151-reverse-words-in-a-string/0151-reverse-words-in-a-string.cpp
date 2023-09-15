class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string ans = "";
        int i=0, j=0;
        while(i<s.size() && j<s.size()) {
            while(i<s.size() && s[i] == ' ') i+=1;
            j=i;
            if(j>=s.size()) break;
            while(j<s.size() && s[j] != ' ') j+=1;
            ans = s.substr(i, j-i) + " " + ans;
            i = j;
        }
        return ans.substr(0,ans.size()-1);
    }
};