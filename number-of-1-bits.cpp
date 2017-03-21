class Solution {
public:
    int hammingWeight(uint32_t n) {
        auto x = n;
        int result = 0;
        while(x > 0){
            result += (x & 1);
            x >>= 1;
        }
        return result;
    }
};
