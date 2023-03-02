class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        for(int i=0;i<chars.size();i++) {
            ans.push_back(chars[i]);
            int j = i+1, count = 0;
            while(j<chars.size() && chars[j] == chars[i]) {
                j+=1;
                count+=1;
            }
            if(count>0) {
                cout << count << endl;
                i += count;
                string s = to_string(count+1);
                for(int k=0;k<s.size();k++) ans.push_back(s[k]);
            }
        }
        // for(int i=0;i<ans.size();i++) {
        //     cout << ans[i] << endl;
        // }
        chars = ans;
        return ans.size();
    }
};