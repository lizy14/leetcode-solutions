class Solution {
public:
    bool isPowerOfTwo(int n) {
        // clear lsb and test if is zero
        return (n > 0) && ! (n & (n-1));
    }
};
