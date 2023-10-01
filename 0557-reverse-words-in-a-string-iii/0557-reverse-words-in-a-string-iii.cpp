class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0;
        int n = s.length();
        while(end<n) {
            while(end < n && s[end] != ' ') end += 1;
            int n = end-start+1;
            // cout << start << " " << end << endl;
            for(int i=0;i<n/2;i++) {
                swap(s[start+i], s[end-i-1]);
            }
            end += 1;
            start = end;
            // cout << s << endl;
        }
        return s;
    }
};