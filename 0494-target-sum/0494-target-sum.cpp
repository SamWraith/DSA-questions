class Solution {
private:
    int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp) {
        // Base case: If we are at the first element.
        if (ind == 0) {
            /* If target is 0 and the element is also 0,there 
            are 2 ways to achieve this (include or exclude).*/
            if (target == 0 && arr[0] == 0)
                return 2;
                
            /* If target is 0 or the element is equal to 
            target, there is 1 way to achieve this*/
            if (target == 0 || target == arr[0])
                return 1;
                
            return 0; 
        }
        
        // Return the result if it has already been computed.
        if (dp[ind][target] != -1)
            return dp[ind][target];
        
        /* Calculate the number of ways not
        including the current element.*/
        int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);
        
        /* Calculate the number of ways including the
        current element (if it can be included).*/
        int taken = 0;
        if (arr[ind] <= target)
            taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);
        
        /* Store and return the result 
        for the current subproblem.*/
        return dp[ind][target] = (notTaken + taken) ;
    }


    /* Function to count number of subsets with a
    given difference.Uses the helper function 
    `countPartitionsUtil` to find the number of subsets
    with a specific target sum. */
    int countPartitions(int n, int diff, vector<int>& arr) {
        int totSum = 0;
        
        // Calculate the total sum of elements in the array.
        for (int i = 0; i < arr.size(); i++) {
            totSum += arr[i];
        }
        
        /* If the total sum minus the difference is negative,
        or if it is not even, it's not possible to divide 
        the array into two subsets with the given difference.*/
        if (totSum - diff < 0) return 0;
        if ((totSum - diff) % 2 == 1) return 0;
        
        // Calculate the target sum for one of the subsets.
        int s2 = (totSum - diff) / 2;
        
        // Initialize the DP table with -1 for memoization.
        vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
        
        /* Call the helper function to count
        the number of subsets with sum s2.*/
        return countPartitionsUtil(n - 1, s2, arr, dp);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};