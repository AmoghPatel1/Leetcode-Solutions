//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        int ans = 0, capital = 0, small = 0;
        for(int i=0;i<S.size();i++) {
            capital = 0;
            small = 0;
            for(int j=i;j<S.size();j++){
                if(S[j] >= 'a' && S[j] <= 'z') small += 1;
                else capital += 1;
                if(small == capital and small != 0) ans += 1;
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends