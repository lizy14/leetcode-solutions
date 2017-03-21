class Solution {
public:
    bool isPowerOfThree(int n) {
        long double x = n;
        long double b = 3;
        auto result = log(x) / log(b);
        return abs((int)result - result) < 1e-10;
    }
    bool isPowerOfThreeTrivial(int n) {
        auto x = n;
        if(x < 1){
            return false;
        }
        while(n % 3 == 0){
            n /= 3;
        }
        return n == 1;
    }
};
