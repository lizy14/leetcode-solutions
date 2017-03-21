class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto n = nums.size();
        for(int i=0; i<n; i++){
            auto& num = nums[i];
            while(num < n && nums[num] != num){
                std::swap(num, nums[num]);
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i] != i){
                return i;
            }
        }
        return n;
    }
};
