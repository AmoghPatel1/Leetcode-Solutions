class Solution {
public:
//     void showpq(priority_queue<int> gq) {
//         priority_queue<int> g = gq;
//         while (!g.empty()) {
//             cout << '\t' << g.top();
//             g.pop();
//         }
//         cout << '\n';
//     }
    
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(), piles.end());
        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        for(int i=0;i<k;i++) {
            // showpq(heap);
            int cur = heap.top();
            heap.pop();
            int remove = cur/2;
            totalSum -= remove;
            heap.push(cur-remove);
            
        }
        // showpq(heap);
        return totalSum;
    }
};