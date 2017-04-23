class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int m = n - 1;
        // invariant: [m, n) in decreasing order
        while(m > 0){
            if(nums[m - 1] >= nums[m]){
                m --;
            }else{
                break;
            }
        }
        
        if(m == 0){
            std::reverse(nums.begin(), nums.end());
            return;
        }
        
        int c = nums[m - 1];
        
        int s = nums[m]; // the smallest and last in [m, n) to > c
        int k = m; // subscript of s
        
        for(int i = m + 1; i < n; i ++){
            auto a = nums[i];
            if(a > c && a <= s){
                s = a;
                k = i;
            }
        }
        
        std::swap(nums[k], nums[m - 1]);
        std::reverse(nums.begin() + m, nums.end());
        return;
    }
};
