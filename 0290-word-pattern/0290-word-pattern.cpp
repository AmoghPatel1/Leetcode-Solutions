class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        int j=0;
        for(int i=0;i<s.length();i++) {
            if(s[i] == ' ') {
                v.push_back(s.substr(j, i-j));
                j = i+1;
            }
        }
        v.push_back(s.substr(j, s.length()-j));
        // for(auto it:v) {
        //     cout << it << endl;
        // }
        set<char> s1;
        set<string> s2;
        for(int i=0;i<pattern.size();i++) s1.insert(pattern[i]);
        for(int i=0;i<v.size();i++) s2.insert(v[i]);
        if(s1.size() != s2.size()) return false;
        map<char, string> m;
        if(pattern.length() != v.size()) return false;
        for(int i=0;i<v.size();i++) {
            // cout << "yes" << endl;
            if(m.find(pattern[i]) == m.end()) 
                m[pattern[i]] = v[i];
            else
                if(m[pattern[i]] != v[i]) return false;
        }
        
        return true;   
    }
};