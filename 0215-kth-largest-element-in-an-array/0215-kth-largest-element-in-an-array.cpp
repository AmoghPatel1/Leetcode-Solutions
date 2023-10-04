class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto x: nums) pq.push(x);
        k-=1;
        while(k-->0) pq.pop();
        return pq.top();
    }
};