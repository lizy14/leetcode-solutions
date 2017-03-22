class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto n = nums.size();
        int counter = 0;
        for(int i=0; i<n; i++){
            nums[counter] = nums[i];
            if(nums[i] != 0){
                counter++;
            }
        }
        for(int i=counter; i<n; i++){
            nums[i] = 0;
        }
    }
};
