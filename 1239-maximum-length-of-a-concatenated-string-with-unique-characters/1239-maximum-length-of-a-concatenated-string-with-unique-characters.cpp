class Solution {
public:
    static bool comp(string a, string b) {
        return a.length() > b.length();
    }
    
    bool uniqueString(string s) {
        set<char> st;
        for(int i:s) {
            st.insert(i);
        }
        return st.size() == s.length();
    }
    
    int maxLength(vector<string>& arr) {
        int maxlength=0;
        int n=arr.size();
        int nos=pow(2,n)-1;
        for(int num=0;num<=nos;num++)
        {
            vector<string> temp;
            for(int i=0;i<n;i++)
            {
                int bit=(num&(1<<i));
                if(bit) temp.push_back(arr[i]);
            }
            string s1="";
            for(int i=0;i<temp.size();i++)
            {
                s1+=temp[i];
            }
            int freq[26]={0};
            for(int i=0;i<s1.size();i++)
            {
                freq[s1[i]-'a']++;
            }
            int cnt=0;
            for(int i=0;i<26;i++)
            {
                if(freq[i]==1)
                {
                    cnt++;
                }
                else if(freq[i]>1)
                {
                    cnt=0;
                    break;
                }
            }
            maxlength=max(maxlength,cnt);            
        }
        return maxlength;
    }
};