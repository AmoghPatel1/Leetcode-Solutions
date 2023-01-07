class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = accumulate(gas.begin(), gas.end(), 0);
        int costSum = accumulate(cost.begin(), cost.end(), 0);
        if(gasSum >= costSum) {
            vector<int> rem;
            int n = gas.size();
            int total = 0, ind = 0;
            for(int i=0;i<n;i++) {
                total += gas[i]-cost[i];
                if(total < 0) {
                    total = 0;
                    ind = i+1;
                }
            }
            return ind;
        }
        return -1;
    }
};