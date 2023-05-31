class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int l = n+m;
        if(l%2==0) {
            return (nums1[l/2]*1.0 + nums1[(l-2)/2]*1.0)/2;
        } else {
            return nums1[(n+m)/2]*1.0;
        }
    }
};