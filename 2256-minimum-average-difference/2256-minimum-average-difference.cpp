class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
            sum += nums[i];
        long long cur = 0;
        int index = 0;
        long long min = 1e5;
        long long firstHalf = 0, secondHalf = 0;
        long long avr = 0;
        for(int i=0;i<n;i++) {
            if(i==n-1) {
                firstHalf = sum/n;
                secondHalf = 0;
            } else {
                cur += nums[i];
                firstHalf = cur/(i+1);
                secondHalf = (sum-cur)/(n-i-1);
            }
            avr = abs(firstHalf-secondHalf);
            if(avr < min) {
                min = avr;
                index = i;
            }
            // cout << firstHalf << " " << secondHalf << " " << min << endl;
        }
        return index;
    }
};