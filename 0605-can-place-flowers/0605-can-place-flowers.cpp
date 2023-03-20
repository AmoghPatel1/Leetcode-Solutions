class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int m) {
        if(m == 0) return true;
        int count = 0, n = flowerbed.size();
        if(n == 1 && m == 1) {
            if(flowerbed[0] == 0)return true;
            else return false;
        }
        for(int i=0;i<n;i++) {
            if(i==0 && flowerbed[i]==0 && i+1<n && flowerbed[i+1]==0) {
                count += 1;
                flowerbed[i] = 1;
            } else if(i==n-1 && flowerbed[i-1] == 0 && flowerbed[i] == 0){
                count += 1;
                flowerbed[i] = 1;
            } else {
                if(flowerbed[i] == 0 && i+1<n && flowerbed[i+1] == 0 && flowerbed[i-1] == 0) {
                    count += 1;
                    flowerbed[i] = 1;
                }
            }
        }
        if(count >= m) return true;
        return false;
    }
};