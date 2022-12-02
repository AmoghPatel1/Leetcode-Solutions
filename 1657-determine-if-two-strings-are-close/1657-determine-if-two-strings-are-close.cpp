class Solution {
public:

    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        set<char> s1,s2;
        vector<int> v1(26,0),v2(26,0);
        for(int i=0;i<word1.length();i++) {
            s1.insert(word1[i]);
            v1[word1[i]-'a']+=1;
        }
        for(int i=0;i<word2.length();i++) {
            s2.insert(word2[i]);
            v2[word2[i]-'a']+=1;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return s1==s2 && v1==v2;
    }
};