class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = n-1;
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<l;j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i] = temp;
            }
            l-=1;
        }
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i=0;i<n/2;i++) {
            for(int j=0;j<n;j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][j];
                matrix[n-1-i][j] = temp;
            }
        }
        
    }
};