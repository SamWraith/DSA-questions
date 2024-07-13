class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans = "";

        int n = s.size();
        k = k % n;
        for(int i = 0; i<s.size(); i++){
            ans += s[(i + k) % n];
            
        }
        return ans;

        
        // for(int i = 0; i<s.size(); i++){
        //     int index = i;
        //     int c = k;
        //     while(c--){
        //         if(index >= s.size()){
        //             index = 0;
        //         }
        //         index++;
        //     }
        //     if(index >= s.size()) index = 0;
        //     ans += s[index];
        // }
        // return ans;
    }
};