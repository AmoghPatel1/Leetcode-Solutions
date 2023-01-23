//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void pathFinder(int row, int col, string s, vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> &visited, int di[], int dj[]) {
        if(row == n-1 && col == n-1) {
            ans.push_back(s);
            return;
        }
        string dir = "DLRU";
        for(int i=0;i<4;i++) {
            int nexti = row + di[i];
            int nextj = col + dj[i];
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !visited[nexti][nextj] && m[nexti][nextj] == 1) {
                visited[row][col] = 1;
                pathFinder(nexti, nextj, s+dir[i], m, n, ans, visited, di, dj);
                visited[row][col] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int> (n,0));
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if(m[0][0] == 1) pathFinder(0, 0, "", m, n, ans, visited, di, dj);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends