class Solution {
public:
    int partitionString(string s) {
        set<char> st;
        int ans = 0;
        for(int i=0;i<s.size();i++) {
            // cout << mp[s[i]] << endl;
            if(st.find(s[i]) != st.end()) {
                ans += 1;
                st.clear();
            }
            st.insert(s[i]);
        }
        return ans+1;
    }
};