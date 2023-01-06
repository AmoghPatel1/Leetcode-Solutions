class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0, cur = 0;
        for(int i=0;i<costs.size();i++) {
            cur += costs[i];
            if(cur > coins) return count;
            else count += 1;
        }
        return count;
    }
};