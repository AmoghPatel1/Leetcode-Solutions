class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> v;
        for(int i=0;i<rectangles.size();i++) {
            v.push_back(min(rectangles[i][0], rectangles[i][1]));
        }
        int maxm = *max_element(v.begin(),v.end());
        int count = 0;
        for(int i=0;i<v.size();i++){
            if(v[i] == maxm) count+=1;
        }
        return count;
    }
};