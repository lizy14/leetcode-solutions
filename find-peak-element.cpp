class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        bool left = true;
        auto n = nums.size();
        for(int i=0; i<n; i++){
            bool right = (i == n-1) || (nums[i] > nums[i+1]);
            if(left && right){
                return i;
            }
            left = ! right;
        }
    }
};
