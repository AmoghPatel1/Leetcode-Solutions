class Solution {
public:
    
    static bool comp(pair<char,int> &a, pair<char,int> &b) {
        return a.second > b.second;    
    }
    
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto it:s){
            mp[it]+=1;
        }
        vector<pair<char,int>> v;
        for(auto it:mp){
            v.push_back(it);
        }
        sort(v.begin(), v.end(), comp);
        // for(int i=0;i<v.size();i++) {
        //     cout << v[i].first << " " << v[i].second << endl;
        // }
        string str = "";
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[i].second;j++) {
                str += v[i].first;
            }
        }
        
        return str;
    }
};