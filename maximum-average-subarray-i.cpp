class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        assert(n >= k);
        
        int sum = 0;
        for(int i=0; i<k; ++i){
            sum += nums[i];
        }
        
        int max_sum = sum;
        
        for(int i=1; i <= n-k; ++i){
            // i: starting point
            sum -= nums[i-1];
            sum += nums[i+k-1];
            max_sum = max(sum, max_sum);
        }
        
        return max_sum / (k + 0.);
    }
};
