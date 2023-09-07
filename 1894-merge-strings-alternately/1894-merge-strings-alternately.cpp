class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0, j=0;
        int n1 = word1.length(), n2 = word2.length();
        string ans;
        int turn = 1;
        while(i<n1 && j<n2) {
            if(turn%2) { 
                ans += word1[i];
                i+=1;
            } else {
                ans += word2[j];
                j+=1;
            }
            turn += 1;
        }

        while(i<n1) ans += word1[i++];
        while(j<n2) ans += word2[j++];

        return ans;
    }
};