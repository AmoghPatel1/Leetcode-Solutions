class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string cur = "";
        int n = s.size();
        for(int j=0;j<n/2;j++) {
            cur += s[j];
            int size = cur.size();
            cout << n << " " << size << endl;
            if(n%size == 0) {
                string str = "";
                for(int i=0;i<(s.size()/cur.size());i++) {
                    str += cur;
                }
                if(str == s) return true;
            }
        }
        return false;
    }
};