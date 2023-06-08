class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "1";
        for(int i=2;i<=n;i++) {
            s += to_string(i);
        }
        while(k>1) {
            next_permutation(s.begin(), s.end());
            k-=1;
        }
        return s;
    }
};