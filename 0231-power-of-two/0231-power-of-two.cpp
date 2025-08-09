class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && log2(n)==(int)log2(n);
    }
};