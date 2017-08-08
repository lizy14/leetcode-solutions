class Solution {
public:
    int minSteps(int n) {
        if(n <= 1){
            return 0;
        }
        int result = n;
        for(int k = 2; k <= sqrt(n); ++k){
            if(n % k == 0){
                result = min(result, k + minSteps(n / k));
            }
        }
        
        return result;
    }
};
