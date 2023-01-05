class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 0;
        
        for(int i=0;i<points.size();i++) {
            count += 1;
            int j = i;
            while(i+1<points.size() && points[i+1][0] <= points[j][1]) {
                if(points[i+1][1] < points[j][1]) j = i+1;
                i+=1;
            } 
        }
        return count;
    }
};