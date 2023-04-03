class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int left = 0, right = n-1, ans = 0;
        int maxm = -1;
        while(left < right) {
            if(people[left] + people[right] <= limit) {
                maxm = max(right, maxm);
                left += 1;
                ans += 1;
            } 
            right -= 1;
        }
        ans = n - ans;
        return ans;
    }
};