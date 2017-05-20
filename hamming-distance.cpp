class Solution {
public:
    int hammingDistance(int x, int y) {
        return countBits(x ^ y);
    }
private:
    int countBits(int x){
        int sum = 0;
        while(x){
            sum ++;
            x &= (x-1);
        }
        return sum;
    }
};
