class Solution {
public:
    int countStudents(vector<int>& arr, int pages) {
        int cntStudent = 1, pagesOfStud = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (pagesOfStud + arr[i] <= pages)
                pagesOfStud += arr[i];
            else {
                cntStudent++;
                pagesOfStud = arr[i];
            }
        }
        return cntStudent;
    }

    int findPages(vector<int>& arr, int n, int m) {
        // Write your code here.
        if (n < m)
            return -1;
        int low, high = 0;
        for (auto it : arr) {
            low = max(low, it);
            high += it;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int noOfStudents = countStudents(arr, mid);
            if (noOfStudents > m)
                low = mid + 1;
            else {

                high = mid - 1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, nums.size(), k);
    }
};