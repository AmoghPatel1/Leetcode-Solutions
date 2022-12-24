class Solution {
public:
    int numTilings(int n) {
        if(n<=2) return n;
        if(n==3) return 5;
        int mod = 1e9 + 7;
        long long last=5, sLast=2, tLast= 1, cur;
        for(int i=3;i<n;i++) {
            // cout << tLast << " " << sLast << " " << last << " " << cur << endl;
            cur = (2*last + tLast)%mod;
            tLast = (sLast)%mod;
            sLast = (last)%mod;
            last = (cur)%mod;
        }
        return last;
    }
};