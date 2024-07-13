class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low ) / 2;
            if(arr[mid] == target) return true;

            // eliminate unique condition
            if(arr[low] == arr[mid] && arr[mid] == arr[high]){
                low++;
                high--;
                continue;
            }
            // left half is sorted
            if(arr[low] <= arr[mid]){
                if(arr[low] <= target && target <= arr[mid]){
                    high = mid  - 1;

                }
                else
                    low = mid + 1;

            }
            //  right half sorted
            else{
                if(arr[mid] <= target && target <= arr[high]){
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
        }
        return false;
        
    }
};