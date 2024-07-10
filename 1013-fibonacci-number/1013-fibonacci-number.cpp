class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int ans = 0;
        int prev2 = 0, prev = 1;
        for(int i=2;i<=n;i++) {
            ans = prev + prev2;
            prev2 = prev;
            prev = ans;             
        }

        return prev;
    }
};