class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int val = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == 'E') {
                val += 1;
                ans = max(ans, val);
            } else val -= 1;
        }
        return ans;
    }
};