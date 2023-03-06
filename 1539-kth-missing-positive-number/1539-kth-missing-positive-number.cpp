class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 1, j=0;
        while(k>0) {
            if(j<arr.size() && arr[j] == i) {
                i += 1;
                j += 1;
            } else {
                i+=1;
                k--;
            }
        }
        return i-1;
    }
};