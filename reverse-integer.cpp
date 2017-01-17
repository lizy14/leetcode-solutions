class Solution {
public:
    int reverse(int x) {
        long long int result = 0;
        bool positive = (x>0);
        long long int y = positive?x:-x;
        while(y){
            result *= 10;
            result += y % 10;
            y /= 10;
        }
        if(!positive) result *= -1;
        if(result != (int)result)
            return 0;
        return result;
    }
};
