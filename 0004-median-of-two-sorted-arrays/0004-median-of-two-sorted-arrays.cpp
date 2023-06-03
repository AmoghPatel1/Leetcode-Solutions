class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> v;
        int i=0,j=0;
        while(i<m&&j<n) {
            if(nums1[i] < nums2[j]) { v.push_back(nums1[i]); i+=1; }
            else {
                v.push_back(nums2[j]);
                j+=1;
            }
        }
        while(i<m) {
            v.push_back(nums1[i]);
            i+=1;
        }
        while(j<n) {
            v.push_back(nums2[j]);
            j+=1;
        }
        int len = m+n;
        if(len%2==0) return ((double)v[len/2] + (double)v[(len-1)/2])/2;
        else return v[len/2];
    }
};