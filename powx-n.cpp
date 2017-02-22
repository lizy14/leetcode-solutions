class Solution {
public:
    double myPow(double x, int n) {
        if(n>0){
            return myPowPositive(x, n);
        }else{
            if(n == INT_MIN){
                return myPow(x, n+1) / x;
            }
            return 1./myPowPositive(x, -n);
        }
    }
private:
    double myPowPositive(double x, int n){
        if(n>2){
            double half = myPowPositive(x, n/2);
            double result = half * half;
            if(n % 2){
                result *= x;
            }
            return result;
        }else{
            double result = 1;
            for(int i=0; i<n; i++){
                result *= x;
            }
            return result;
        }
    }
};
