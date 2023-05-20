class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMaxHeight, rightMaxHeight;
        int h = 0, n = height.size();
        for(int i=0;i<n;i++) {
            h = max(h, height[i]);
            leftMaxHeight.push_back(h);
        }
        
        h = 0;
        for(int i=n-1;i>=0;i--) {
            h = max(h, height[i]);
            rightMaxHeight.push_back(h);
        }
        reverse(rightMaxHeight.begin(), rightMaxHeight.end());
        
        int ans = 0;
        cout << ans << " ";
        for(int i=1;i<n-1;i++) {
            int water = min(leftMaxHeight[i], rightMaxHeight[i]) - height[i];
            if(water > 0) ans += water;
        }
        return ans;
    }
};