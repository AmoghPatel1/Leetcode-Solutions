class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int n = senate.size();

        queue<int> rQueue;
        queue<int> dQueue;

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                rQueue.push(i);
            } else {
                dQueue.push(i);
            }
        }

        while (!rQueue.empty() && !dQueue.empty()) {
            
            int rTurn = rQueue.front();
            rQueue.pop();
            int dTurn = dQueue.front();
            dQueue.pop();

            // ONE having a larger index will be banned by a lower index
            // Lower index will again get Turn, so EN-Queue again
            // But ensure its turn comes in the next round only
            if (dTurn < rTurn) {
                dQueue.push(dTurn + n);
            } else {
                rQueue.push(rTurn + n);
            }
        }

        // One's which Empty is not winner
        return rQueue.empty() ? "Dire" : "Radiant";
    };
};