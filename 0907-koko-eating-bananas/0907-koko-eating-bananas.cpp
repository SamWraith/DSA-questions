class Solution {
public:
    long long totalHours(vector<int>& piles, int k){
        long long  totalH = 0 * 1LL; // don't forget to initialise it with 0
        for(int i = 0; i< piles.size(); i++){
            totalH += ceil((double)piles[i] / (double)k );
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = INT_MIN;
        for(int i: piles){
            maxi = max(maxi, i);
        }

        int low = 1, high = maxi, ans = INT_MIN;
        while(low <= high){
            long long  mid = low + (high - low) /2;
            long long  totalH = totalHours(piles, mid);
            if(totalH <= h){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};