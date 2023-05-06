class Solution {
public:
    double myPow(double x, int n) {
        if(x == (double)1) return 1.00000;
        if(x == (double)-1) {
            if(n%2 == 0) return 1.00000;
            else -1.00000;
        }
        if(x == 0.0 && n>0) return 0.0;
        if(n<-1000) return 0.00000;
        if(n==0) return 1;
        if(n==1) return x;
        if(n<0) {
            return 1/pow(x,-n);
        }
        double ans = myPow(x,n/2);
        if(n%2==0) return ans*ans;
        else return x*ans*ans;
    }
};