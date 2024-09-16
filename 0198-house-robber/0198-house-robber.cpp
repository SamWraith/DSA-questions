class Solution {
private:
    int solve(int i, vector<int> &nums){
        if(i == 0) return nums[i];
        if(i < 0) return 0;

        int take = nums[i] + solve(i - 2, nums);
        int nottake = 0 + solve(i - 1, nums);
        return max(take, nottake);
    }
    int mem(int i, vector<int> &nums, vector<int> &dp){
        if(i == 0) return nums[i];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + mem(i - 2, nums, dp);
        int nottake = 0 + mem(i - 1, nums, dp);
        return dp[i] = max(take, nottake);
    }
    int tab(int n, vector<int> &nums){
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i<n; i++){
            int take = nums[i];
            if(i > 1)
                take += dp[i - 2];
            int nottake = 0 + dp[i - 1];
            dp[i] = max(take, nottake);
        }
        return dp[n - 1];
    }
    int space(int n, vector<int> &nums){
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i<n; i++){
            int take = nums[i];
            if(i > 1)
                take += prev2;
            int nottake = 0 + prev;
            int curr = max(take, nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return solve(n - 1, nums);
        // vector<int> dp(n, -1);
        // return mem(n - 1, nums, dp);
        // return tab(n, nums);
        return space(n, nums);
    }
};