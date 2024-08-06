class Solution {
public:
    int findDays(vector<int> &weights, int capacity){
        int load = 0;
        int days = 1;
        for(int i = 0; i<weights.size(); i++){

            load += weights[i];
            if(load > capacity){
                load = weights[i];
                days++;
            }
        
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = -1;
        int high = 0;
        int n = weights.size();
        for(int i = 0; i<n; i++){
            low = max(low, weights[i]);
            high += weights[i];
        }
        int ans;
        while(low <= high){
            int mid = low + (high - low) /2;
            if(findDays(weights, mid) <= days){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans; // or return low
    }
};