class Solution {
public:
    bool halvesAreAlike(string s) {
        int count = 0;
        int n = s.length()/2;
        for(int i=0;i<n;i++) {
            char ch = tolower(s[i]);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') count += 1;
            ch = tolower(s[i+n]);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') count -= 1;
        }
        return count == 0;
    }
};