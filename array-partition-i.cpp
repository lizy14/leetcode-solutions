class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0; i<n/2; i++){
            sum += nums[2*i];
        }
        return sum;
    }
};
