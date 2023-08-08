class Solution {
public:
    int merge(vector<int> &arr, int low, int mid, int high) {
        // counting reverse pairs
        int pairs = 0;     
        int p = low, q = mid+1, r = 0;
        for(int p = low; p <= mid; p++) {
            while(q <= high && (long long) arr[p] > (long long)2*arr[q]) {
                q++;
            } 
            pairs += q-mid-1;
        }

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

        return pairs;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int pairs = 0;
        if(low>=high) return 0;
        int mid = low + (high-low)/2;
        pairs += mergeSort(arr, low, mid);
        pairs += mergeSort(arr, mid+1, high);
        pairs += merge(arr, low, mid, high);
        return pairs;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};