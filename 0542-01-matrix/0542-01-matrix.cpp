#include<bits/stdc++.h>
class Solution {

struct PairHash {
  template <typename T1, typename T2>
  auto operator()(const pair<T1, T2> &p) const -> size_t {
    return hash<T1>{}(p.first) ^ hash<T2>{}(p.second);
  }
};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_set<pair<int,int>, PairHash> st;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 0) {
                    st.insert(make_pair(i,j));
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int dis = INT_MAX; 
                if(mat[i][j] != 0){
                    for(auto it: st) {
                        dis = min(dis, abs(it.first - i) + abs(it.second - j));
                    }
                    mat[i][j] = dis;
                } else mat[i][j] = 0;
            }
        }
        return mat;
    }
};