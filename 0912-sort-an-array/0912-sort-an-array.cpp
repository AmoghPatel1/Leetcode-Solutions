class Solution {
public:    
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int i = low, j = mid+1;
        while(i<=mid && j<=high) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i+=1;
            } else {
                temp.push_back(arr[j]);
                j+=1;
            }
        }
        while(i<=mid) {
            temp.push_back(arr[i]);
            i+=1;
        }
        while(j<=high) {
            temp.push_back(arr[j]);
            j+=1;
        }

        for(int k=0;k<temp.size();k++) {
            arr[k+low] = temp[k];
        }
    }

    void mergeSort(vector<int> &arr, int low, int high) {
        if(low>=high) return;
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};
