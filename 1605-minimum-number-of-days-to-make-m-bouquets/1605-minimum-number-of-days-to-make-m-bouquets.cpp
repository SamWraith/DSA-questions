class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0, noOfB = 0;
        for(int i = 0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                noOfB += cnt/k;
                cnt = 0;
            }
        }
        noOfB += cnt/k;
        return noOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        int n = bloomDay.size();
        if(val > n) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i: bloomDay){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        int low = mini, high = maxi, ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) /2;
            if(possible(bloomDay, mid, m, k) == true){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};