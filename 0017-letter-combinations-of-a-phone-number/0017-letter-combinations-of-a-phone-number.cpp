#include<bits/stdc++.h>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<char,string> mp;
        mp['2']="abc"; mp['3']="def"; mp['4']="ghi"; mp['5']="jkl"; mp['6']="mno"; mp['7']="pqrs"; mp['8']="tuv"; mp['9']="wxyz";
        
        for(int k=0;k<digits.size();k++) {
            string str = mp[digits[k]];
            if(k != 0) {
                vector<string> vec;
                for(int i=0;i<ans.size();i++) {
                    for(int j=0;j<str.size();j++) {
                        vec.push_back(ans[i] + str[j]);
                    }
                }
                ans.assign(vec.begin(), vec.end());
            } else {
                for(auto y: str) {
                    string sg = "";
                    ans.push_back(sg+y);
                }
            }
        }
        return ans;
    }
};