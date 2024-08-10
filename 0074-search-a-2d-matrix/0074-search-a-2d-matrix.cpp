class Solution {
public:
    bool binarySearch(vector<int> matrix, int target){
        int low = 0, high = matrix.size() - 1;
        while(low <= high){
            int mid = low + (high - low ) /2;
            if(matrix[mid] == target)
                return true;
            else if(matrix[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i<matrix.size(); i++){
            if(binarySearch(matrix[i], target))
                return true;
        }
        return false;
    }
};