class Solution {
public:
    void solve(vector<int> ds, vector<int> nums, vector<vector<int>> &ans, vector<int> &freq, int n){
        if(ds.size() == n){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i<n; i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                solve(ds, nums, ans, freq, n);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n, 0);
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ds, nums, ans, freq, n);
        return ans;
    }
};