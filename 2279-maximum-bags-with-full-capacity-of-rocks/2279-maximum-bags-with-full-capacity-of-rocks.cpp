class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int count = 0, n = capacity.size();
        for(int i=0;i<n;i++)
            capacity[i] -= rocks[i];
        sort(capacity.begin(),capacity.end());
        // for(int i=0;i<n;i++) cout << capacity[i] << " ";
        for(int i=0;i<n;i++){
            if(capacity[i] <= 0) count+=1;
            else {
                if(capacity[i] <= additionalRocks) {
                    count+=1;
                    additionalRocks -= capacity[i];
                } else break;
            }
        }
        return count;
    }
};