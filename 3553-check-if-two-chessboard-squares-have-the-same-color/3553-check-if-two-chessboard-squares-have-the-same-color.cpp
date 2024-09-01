class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int val = (coordinate1[0]-coordinate2[0]) + (coordinate1[1]-coordinate2[1]);
        return val%2==0;
    }
};