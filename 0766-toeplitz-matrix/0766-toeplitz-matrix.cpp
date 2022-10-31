class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        map<int,int> mp;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mp.find(i-j) == mp.end())
                    mp[i-j] = matrix[i][j];
                else if(mp[i-j] != matrix[i][j])
                    return false;
            }
        }
        return true;
    }
};