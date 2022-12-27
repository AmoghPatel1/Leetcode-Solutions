class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        map<int,int> mp;
        int count = 0;
        for(int i=0;i<capacity.size();i++) {
            if(capacity[i] > rocks[i]) {
                mp[capacity[i]-rocks[i]] += 1;
            } else {
                count += 1;
            }
        }
        for(auto it:mp) {
            if(it.first <= additionalRocks) {
                int cnt = it.first*it.second;
                // cout << cnt << endl;
                if(cnt >= additionalRocks) {
                    count += additionalRocks/it.first;
                    return count;
                } else {
                    count += it.second;
                    additionalRocks -= cnt;
                }
            } else break;
        }
        return count;
    }
};