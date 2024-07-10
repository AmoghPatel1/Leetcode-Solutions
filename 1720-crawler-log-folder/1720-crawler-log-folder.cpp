class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto it: logs) {
            if(it == "../") {
                if(ans == 0) continue;
                else ans -= 1;
            } else if(it == "./") {
                continue;
            } else {
                ans += 1;
            }
        }
        return ans;
    }
};