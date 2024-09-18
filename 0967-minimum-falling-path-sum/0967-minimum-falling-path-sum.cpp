class Solution {
private:
    int solve(int i, int j, vector<vector<int>> &matrix){
        if(j < 0 || j >= matrix[0].size()) return 1e9;
        if(i == 0) return matrix[i][j];
        int up = matrix[i][j] + solve(i - 1, j, matrix);
        int ld = matrix[i][j] + solve(i - 1, j - 1, matrix);
        int rd = matrix[i][j] + solve(i - 1, j + 1, matrix);
        return min(up, min(ld, rd));
    }
    int mem(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(j < 0 || j >= matrix[0].size()) return 1e9;
        if(i == 0) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int up = matrix[i][j] + mem(i - 1, j, matrix, dp);
        int ld = matrix[i][j] + mem(i - 1, j - 1, matrix, dp);
        int rd = matrix[i][j] + mem(i - 1, j + 1, matrix, dp);
        return dp[i][j] = min(up, min(ld, rd));
    }
    int tab(vector<vector<int>> &matrix, int n, int m){
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i<m; i++)
            dp[0][i] = matrix[0][i];
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                int up = matrix[i][j] + dp[i - 1][j];
                int ld = matrix[i][j];
                if(j>0) ld += dp[i - 1][j - 1];
                else ld = 1e9;
                int rd = matrix[i][j];
                if(j<m-1) rd += dp[i - 1][j + 1];
                else rd = 1e9;
                dp[i][j] = min(up, min(ld, rd));
            }
        }
        int mini = 1e9;
        for(int i = 0; i<m; i++)
            mini = min(mini, dp[n-1][i]);
        return mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 1e9;
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // for(int i = 0; i<m; i++){

        //     // ans = min(ans, solve(n-1, i, matrix));
        //     // ans = min(ans, mem(n-1, i, matrix, dp));

        // }
        // return ans;


        // tabulation

        return tab(matrix, n, m);
    }
};