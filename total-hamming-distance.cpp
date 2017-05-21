class Solution {
    const static int numberOfBits = sizeof(int) * 8;
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < numberOfBits; ++i){
            int mask = 1 << i;
            int c = 0; // total number of 1 at i-th bit
            for(auto num: nums){
                int bit = (num & mask) >> i;
                c += bit;
            }
            // c 1's and (n-c) 0's
            sum += c * (n-c);
        }
        return sum;
    }

public:
    int totalHammingDistanceNaive(vector<int>& nums) {
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
