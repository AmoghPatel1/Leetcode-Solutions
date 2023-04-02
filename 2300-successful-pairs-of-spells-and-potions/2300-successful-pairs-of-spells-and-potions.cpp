class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v;
        sort(potions.begin(), potions.end());
        int n = potions.size();
        for(int i=0;i<spells.size();i++) {
            if(spells[i]*1LL*potions[n-1] < success) {
                v.push_back(0);
                continue;
            }
            if(spells[i]*1LL*potions[0] > success) {
                v.push_back(n);
                continue;
            }
            int div = success%spells[i] == 0 ? success/spells[i]: (success/spells[i]) + 1;
            // cout << div << endl;
            int ind = lower_bound(potions.begin(), potions.end(), div) - potions.begin();
            v.push_back(n-ind);
        }
        return v;
    }
};