class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        if(s == goal) {
            unordered_map<char,int> mp;
            for(auto it: s) {
                mp[it] += 1;
                if(mp[it] > 1) return true;
            }
            return false;
        }
        unordered_map<char, int> mp1, mp2;
        for(auto it:s) {
            mp1[it] += 1;
        }
        for(auto it: goal) {
            mp2[it] += 1;
        }
        if(mp1 != mp2) return false;
        
        int prev = -1, count = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] != goal[i]) {
                if(prev == -1) {
                    prev = i;
                } else if(count == 1) {
                    if(s[prev] != goal[i] || s[i] != goal[prev]) return false;
                }
                count += 1;
            }
        }
        if(count > 2) 
            return false;
        return true;
    }
};