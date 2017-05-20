class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum = 0;
        for(auto x: nums){
            for(auto y: nums){
                sum += hammingDistance(x, y);    
            }
        }
        return sum / 2;
    }
private:
    inline int hammingDistance(int x, int y) {
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
