public class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        if(m == n){
            return m;
        }
        if(m > n){
            return rangeBitwiseAnd(n, m);
        }
        
        return rangeBitwiseAnd(n >> 1, m >> 1) << 1;
    }
}
