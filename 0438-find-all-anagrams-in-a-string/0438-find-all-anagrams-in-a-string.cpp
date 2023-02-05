class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if(s.size() < p.size()) return v;        
        vector<int> s1(26,0), s2(26,0);
        for(int i=0;i<p.size();i++) {
            s1[p[i]-'a'] += 1;
            s2[s[i]-'a'] += 1;
        }
        if(s1 == s2) v.push_back(0);
        // cout << "SET 1" << " : ";
        // for(auto it: s1) cout << it << " ";
        // cout << endl;
        
        int cur = 1;
        for(int i=p.size();i<s.size();i++) {
            // cout << s[i-p.size()] << " " << s[i] << endl;
            // cout << "SET 2" << " : ";
            // for(auto it:s2) cout << it << " ";
            // cout << endl;
            
            s2[s[i-p.size()]-'a'] -= 1;    
            s2[s[i]-'a'] += 1;
            if(s1 == s2) v.push_back(cur);
            cur+=1;
        }
        // cout << "SET 2" << " : ";
        // for(auto it:s2) cout << it << " ";
        // cout << endl;
        
        return v;
    }
};