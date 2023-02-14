
class Solution {
public:
    string addBinary(string a, string b) {
        int p = a.size(), q = b.size();
        int n = max(p,q);
        int dif = abs(p-q);
        string str(dif+1, '0');
        if(p>=q) {
            b = str + b;
            a = "0" + a;
        } else if(q>p) {
            a = str + a;
            b = "0" + b;
        }
        
        // cout << a << endl;
        // cout << b << endl;
        
        string s(n+1, '0');
        // cout << s << endl;
        // cout << n << endl;
        int carry = 0;
        for(int i=n;i>=0;i--) {
            cout << a[i] << " " << b[i] << " " << carry << endl;
            if(a[i] == '1' && b[i] == '1') {
                if(carry == 1)
                    s[i] = '1';
                else
                    s[i] = '0';
                carry = 1;
            } else if((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) {
                if(carry == 1) {
                    s[i] = '0';
                    carry = 1;
                } else {
                    s[i] = '1';
                    carry = 0;
                }
            } else {
                if(carry == 1){ 
                    s[i] = '1';
                    carry = 0;
                }
            }
            cout << s << endl;
        }
        
        if(s[0] == '0') s = s.substr(1);
        return s;
    }
};



