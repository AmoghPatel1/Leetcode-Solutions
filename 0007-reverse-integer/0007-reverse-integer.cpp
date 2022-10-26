class Solution {
public:
    int reverse(int x) {
        int temp = 0;
        while(x!=0) {
            // cout <<"I'm here" << endl;
            int pop = x % 10;
            x /= 10;
            if(temp > INT_MAX/10 || (temp == INT_MAX / 10 && pop > 7)) return 0;
            if(temp < INT_MIN/10 || (temp == INT_MIN / 10 && pop < -8)) return 0;
            temp = temp * 10 + pop;
        }
        return temp;
    }
};