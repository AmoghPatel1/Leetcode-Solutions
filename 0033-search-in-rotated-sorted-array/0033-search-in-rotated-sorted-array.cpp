class Solution {
public:
    int binarySearch(int l, int r, vector<int> nums, int target) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        } 
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1) if(nums[0] == target) return 0; else return -1; 
        if(nums[0] < nums[n-1]) {
            return binarySearch(0, n-1, nums, target);
        }
        int l = 0, r = n-1, index = -1;
        while(l <= r) {
            index = l + (r-l)/2;
            // cout << index << endl;
            if(index > 0 && nums[index] < nums[index-1]) {
                // cout << nums[index] << " " << nums[index-1] << endl;
                // cout << index << endl;
                break;  
            } 
            else if(nums[index] >= nums[0]) l = index+1;
            else r = index-1;
        }
        cout << index << endl;
        if(target >= nums[0]) return binarySearch(0, index-1, nums, target);
        else return binarySearch(index, n-1, nums, target);
        
    }
};