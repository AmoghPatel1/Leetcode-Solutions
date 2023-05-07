//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        int n = str.size();
        string s = "", minString;
        s += str[0];
        minString = s + s;
        for(int i=1;i<n;i++) {
            if(str[i] -'a' <= str[i-1] -'a') {
                s += str[i];
                string st = s;
                reverse(st.begin(), st.end());
                st = s + st;
                minString = min(minString, st);
            } else break;
        }
        return minString;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends