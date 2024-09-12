class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> allow;
        for(auto ch: allowed)
            allow[ch]++;
        int ans = 0, flag = 1;
        for(auto i: words){
            flag = 1;
            for(auto ch: i){
                if(allow.find(ch) == allow.end()){

                    flag = 0;
                    break;
                }
            }
            if(flag == 1) ans++;

        }
        return ans;
    }
};