class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long ans = 0;
        long long n = enemyEnergies.size(), minm = 1e9;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if(enemyEnergies[0] > currentEnergy) return 0;
        long long sum = 0;
        for(int i=0;i<n;i++) {
            sum += enemyEnergies[i];
        }
        sum += (currentEnergy - enemyEnergies[0]);
        return sum/enemyEnergies[0]*1LL;
    }
};