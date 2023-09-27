class Solution {
public:
    int countDigits(int num) {
        int n = num;
        vector<int> v;
        while(n>0) {
            int digit = n%10;
            v.push_back(digit);
            n/=10;
        }
        int count = 0;
        for(int i=0;i<v.size();i++) {
            if(v[i] != 0 && num%v[i] == 0) count += 1;
        }
        return count;
    }
};