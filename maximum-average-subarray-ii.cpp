class Solution {
public:

    double findMaxAverage(vector<int>& nums, int k) {
        
        double _max = 10000;
        double _min = - _max;
        while(_max - _min >= 1e-6){
            double _mid = (_max + _min) / 2;
            if(existsPositiveSumSubsequence(nums, k, _mid)){
                _min = _mid;
            }else{
                _max = _mid;
            }
        }
        return _min;
    }
    bool existsPositiveSumSubsequence(vector<int>& nums, int k, double offset){
    
        int n = nums.size();
        // prefix sum
        vector<double> prefixSums;
        prefixSums.reserve(n);
        {
            double sum = 0;
            for(int x : nums){
                sum += x;
                sum -= offset;
                prefixSums.push_back(sum);
            }
        }

        if(prefixSums[k-1] > 0){
            return true;
        }
        
        double minSum; // minimun of sum of [0, i]
        bool currentMinAssigned = false;
        for(int i = 0; i < n - k; ++ i){
            double sum = prefixSums[i]; // sum of [0, i]
            
            if(!currentMinAssigned || minSum > sum){
                minSum = min(0., sum); // positive -> 0
                currentMinAssigned = true;
            }

            if(prefixSums[i + k] >= minSum){
                return true;
            }
            
        }
        
        return false;
    }
};
