class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        
        int i=0, j=0;
        while(i<s.size() && j<s.size()) {
            while(i<s.size() && s[i] == ' ') i+=1;
            j=i;
            if(j>=s.size()) break;
            while(j<s.size() && s[j] != ' ') j+=1;
            v.push_back(s.substr(i, j-i));
            i = j;
        }

        string ans = "";
        int n = v.size();
        for(int p=n-1;p>=0;p--) {
            ans += v[p];
            if(p != 0) ans += " ";
        }
        return ans;
    }
};