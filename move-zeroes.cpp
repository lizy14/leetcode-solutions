class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto n = nums.size();
        int counter = 0;
        for(int i=0; i<n-counter; i++){
            if(nums[i] == 0){
                counter++;
                for(int j=i; j<=n-counter; j++){
                    nums[j] = nums[j+1];
                }
                nums[n-1] = 0;
                i--;
            }
        }
    }
};
