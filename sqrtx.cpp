class Solution {
public:
    int mySqrt(int x) {
        if(x<=1){
            return x;
        }
        int upper = x, lower = 1;
        int result;
        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;
            if(mid > x/mid){ //square > x
                upper = mid - 1;
            }else if(mid < x/mid){ //square < x
                lower = mid + 1;
                result = mid; //result <= exact solution
            }else{
                return mid;
            }
        }
        return result;
    }
};
