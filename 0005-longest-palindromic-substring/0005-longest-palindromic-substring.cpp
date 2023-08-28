class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int len = 0, n = s.length();
        for(int i=0;i<n;i++) {
            // Odd Length Palindrome
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right]) {
                if((right-left+1) > len) {
                    len = right-left+1;
                    ans = s.substr(left, len);
                }
                left -= 1;
                right += 1;
            }
            // Even Length Palindrome
            left = i, right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                if((right-left+1) > len) {
                    len = right-left+1;
                    ans = s.substr(left, len);
                }
                left -= 1;
                right += 1;
            }
        }
        return ans;
    }
};