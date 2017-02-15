class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int l_result = 0;
        long long int l_dividend = llabs(dividend);
        long long int l_divisor = llabs(divisor);
        
        int sign_different = (dividend < 0) != (divisor < 0);
        
        while (l_dividend >= l_divisor) { 
            long long int maximum_subtractable = l_divisor;
            long long int multiplier = 1;
            while (l_dividend >= (maximum_subtractable << 1)) {
                maximum_subtractable <<= 1;
                multiplier <<= 1;
            }
            l_dividend -= maximum_subtractable;
            l_result += multiplier;
        }
        
        l_result = sign_different ? -l_result : l_result; 
        
        if(l_result > INT_MAX || l_result < INT_MIN){
            return INT_MAX;
        }
        
        return (int)l_result;
    }
};
