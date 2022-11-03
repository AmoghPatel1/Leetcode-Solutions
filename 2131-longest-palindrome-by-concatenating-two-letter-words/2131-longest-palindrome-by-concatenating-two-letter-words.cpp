class Solution {
    string reverse(string s) {
        char temp = s[0];
        s[0] = s[1];
        s[1] = temp;
        return s;
    }
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        for(int i=0;i<words.size();i++) {
            if(mp.find(words[i]) == mp.end()) {
                mp[words[i]] = 1;
            } else {
                mp[words[i]] += 1;
            }
        }
        int len = 0;
        bool flag = false;
        for(auto it:mp) {
            if(it.first[0] == it.first[1]) {
                if(it.second%2 == 1 && !flag) {
                    flag = true;
                    len+=2;
                }
                len += 4*(it.second/2);
            } else {
                auto k = mp.find(reverse(it.first));
                if(k != mp.end()) {
                    int minm = min(it.second, k->second);
                    len += 4*minm;
                    mp[reverse(it.first)] = 0;
                }
            }
        }
        return len;
    }
};