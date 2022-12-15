class Solution {
public:
    int dp[1010][1010];

    int func(int i, int j,string &s, string &t) {
       if(i < 0 || j < 0) return 0;
       if(dp[i][j] != -1)return dp[i][j];
       if(s[i] == t[j]) return dp[i][j] = 1 + func(i-1,j-1,s,t);
       return dp[i][j] = max(func(i-1,j,s,t),func(i,j-1,s,t));  
    }

    int longestCommonSubsequence(string s, string t) {
        memset(dp,-1, sizeof(int)*1010*1010);
        int n1 = s.length();
        int n2 = t.length();
        return func(n1-1,n2-1,s,t);
    }
};