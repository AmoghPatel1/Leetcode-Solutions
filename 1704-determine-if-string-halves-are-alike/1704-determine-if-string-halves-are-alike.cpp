class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length()/2;
        set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int firstHalfVowelsCount = 0, secondHalfVowelsCount = 0;
        for(int i=0;i<n;i++) {
            if(st.find(s[i]) != st.end()) firstHalfVowelsCount += 1;
            if(st.find(s[i+n]) != st.end()) secondHalfVowelsCount += 1;
        }
        return firstHalfVowelsCount == secondHalfVowelsCount;
    }
};