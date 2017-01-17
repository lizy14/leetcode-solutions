class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        int y=x;
        
        int length = 1;
        while(y/10){
            length *= 10;
            y /= 10;
        }
        
        while(1){
            if(length <= 1)
                return true;
            if(x % 10 != x/length)
                return false;
            x %= length;
            x /= 10;
            length /= 100;
        }
    }
};
