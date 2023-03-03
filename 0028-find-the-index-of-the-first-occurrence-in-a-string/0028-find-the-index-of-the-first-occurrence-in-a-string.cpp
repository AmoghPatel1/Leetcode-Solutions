class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();
        for(int i=0;i<haystack.size();i++) {
            if(haystack[i] == needle[0]) {
                string s = haystack.substr(i, len);
                if(s == needle) return i;
            }
        }
        return -1;
    }
};