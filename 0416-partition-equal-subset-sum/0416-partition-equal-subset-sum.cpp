class Solution {
private:
    bool solve(int i, int target, vector<int> &arr){
        if(target == 0) return true;
        if(i == 0){
            return arr[0] == target;
        }
        bool notTake = solve(i - 1, target, arr);
        bool take = false;
        if(target >= arr[i])
            take = solve(i - 1, target - arr[i], arr);
        return notTake || take;
    }
    bool mem(int i, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(i == 0){
            return arr[0] == target;
        }
        if(dp[i][target] != -1) return dp[i][target];
        bool notTake = mem(i - 1, target, arr, dp);
        bool take = false;
        if(target >= arr[i])
            take = mem(i - 1, target - arr[i], arr, dp);
        return dp[i][target] = notTake || take;
    }
    bool tab(int n, vector<int> &arr, int sum){
        vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
        for(int i = 0; i<n; i++)
            dp[i][0] = true;
        dp[0][arr[0]] = true;
        for(int i = 1; i<n; i++){
            for(int target = 1; target<=sum; target++){
                bool notTake = dp[i - 1][ target];
                bool take = false;
                if(target >= arr[i])
                    take = dp[i - 1][ target - arr[i]];
                dp[i][target] = notTake || take;
            }
        }
        return dp[n-1][sum];
    }
    bool space(int n, vector<int> &arr, int sum){
        vector<bool> prev(sum+1, 0), curr(sum+1, 0);
        prev[0] = curr[0] = true;
        if(arr[0] <= sum) // mentioned by a subs 
            prev[arr[0]] = true;
        for(int i = 1; i<n; i++){
            for(int target = 1; target<=sum; target++){
                bool notTake = prev[ target];
                bool take = false;
                if(target >= arr[i])
                    take = prev[ target - arr[i]];
                curr[target] = notTake || take;
            }
            prev = curr;
        }
        return prev[sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        // return solve(n - 1, sum, arr);
        // vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        // return mem(n - 1, sum, arr, dp);
        // return tab(n, arr, sum);
        return space(n, arr, sum);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        for(auto num: nums)
            tot += num;
        if(tot & 1) return false;
        int target = tot/2;
        return space(n, nums, target);
    }
};