class Solution {
public:
    int partitionString(string s) {
        map<char,int> mp;
        int ans = 0;
        for(int i=0;i<s.size();i++) {
            // cout << mp[s[i]] << endl;
            if(mp[s[i]] > 0) {
                ans += 1;
                mp.clear();
            }
            mp[s[i]] += 1;
        }
        return ans+1;
    }
};