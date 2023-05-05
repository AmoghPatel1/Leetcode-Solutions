class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0, n = s.size();
        int ans = 0;
        for(int i=0;i<k;i++) {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                count += 1;
            }
        }
        ans = count;
        int j;
        for(int i=k;i<n;i++) {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                count += 1;
            }
            j = i-k;
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u') {
                count -= 1;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};