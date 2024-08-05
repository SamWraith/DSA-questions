class Solution {
public:
    int calc(vector<int> &nums, int mid){
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            sum += ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int maxi = INT_MIN;
        int ans = -1;
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        
        int low = 1;
        int high = maxi;
        while(low<= high){  
            
            int mid = low + (high - low) /2;
            int sum = calc(nums, mid);
            
            if(sum <= threshold){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};