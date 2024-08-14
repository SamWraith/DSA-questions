class Solution {
public:
    void solve(int ind, vector<int> num, vector<int> ds, vector<vector<int>> &ans, int n){
      
        ans.push_back(ds);
            
        for(int i = ind; i<n; i++){
            if(i > ind && num[i] == num[i - 1]) continue;
            ds.push_back(num[i]);
            solve(i+1, num, ds, ans, n);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        solve(0, nums, ds, ans, n);
        return ans;
    }
};