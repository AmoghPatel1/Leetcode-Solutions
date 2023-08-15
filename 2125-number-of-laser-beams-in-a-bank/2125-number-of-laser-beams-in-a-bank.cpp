class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for(int i=0;i<bank.size();i++) {
            int count = 0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j] == '1') count += 1;
            }
            if(count > 0) v.push_back(count);
        }
        int ans = 0;
        int n = v.size();
        if(n <= 1) return 0;
        int prev = v[0], cur;
        for(int i=1;i<n;i++) {
            cur = v[i];
            ans += (cur*prev);
            prev = cur;
        }
        return ans;
    }
};