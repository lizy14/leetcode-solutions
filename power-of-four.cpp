class Solution {
public:
    bool isPowerOfFour(int num) {
        auto x = num;
        while(x){
            if(x == 1){
                return true;
            }
            if(x % 4){
                return false;
            }
            x /= 4;
        }
        return false; 
    }
};
