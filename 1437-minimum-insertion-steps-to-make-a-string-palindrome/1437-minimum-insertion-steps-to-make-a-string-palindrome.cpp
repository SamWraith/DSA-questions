class Solution {
private:
    int solve(int i, int j, string &text1, string &text2){
        if(i < 0 || j<0) return 0;
        if(text1[i] == text2[j]) return 1 + solve(i-1, j-1, text1, text2);
        else return max(solve(i-1, j, text1, text2), solve(i, j-1, text1, text2));
    }
    int mem(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        if(i == 0 || j==0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i-1] == text2[j-1]) return dp[i][j] = 1 + mem(i-1, j-1, text1, text2, dp);
        else return dp[i][j] = max(mem(i-1, j, text1, text2, dp), mem(i, j-1, text1, text2, dp));
    }
    int lcs(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        // return solve(n1 - 1, n2 - 1, text1, text2);
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return mem(n1, n2, text1, text2, dp);
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return lcs(s, s2);
    }
public:
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};