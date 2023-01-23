class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 && n == 1) return 1; 
        map<int, vector<int>> mp;
        map<int,int> m;
        for(int i=0;i<trust.size();i++) m[trust[i][0]] = trust[i][1];
        for(int i=0;i<trust.size();i++) {
            mp[trust[i][1]].push_back(trust[i][0]);
        }
        for(auto it: mp) {
            cout << it.first << it.second.size() << endl;
            if(it.second.size() == n-1) {
                for(auto i: m) {
                    cout << i.second << endl;
                    if(m.find(it.first) != m.end()) return -1;
                }
                return it.first;
            } 
        }
        return -1;
    }
};