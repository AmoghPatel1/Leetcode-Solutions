class Solution {
public:
    double average(vector<int>& salary) {
        double minm = (double)salary[0], maxm = (double)salary[0];
        double total = (double)salary[0];
        for(int i=1;i<salary.size();i++) {
            total += (double)salary[i];
            if(salary[i] <= minm) minm = (double)salary[i];
            if(salary[i] >= maxm) maxm = (double)salary[i];
        }
        int n = salary.size()-2;
        return (total-minm-maxm)/n;
    }
};