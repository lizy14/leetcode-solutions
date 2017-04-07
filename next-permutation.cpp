class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int m = n - 1;
        int last_digit = nums[n-1];
        for(; m>=0; m--) {
            int this_digit = nums[m];
            if(this_digit < last_digit) {
                    break;
            }
            last_digit = this_digit;
        }

        // m-th to rightmost in decreasing order

        if(m < 0) {
            std::sort(nums.begin(), nums.end());
            return;
        }

        int candidate = nums[m];

        int s = -1;
        for(int i=m+1; i<n; i++) {
            if(nums[i] > candidate) {
                s = i;
            }
        }

        // s-th: smallest to be greater than

        std::swap(nums[m], nums[s]);

        std::sort(nums.begin() + m + 1, nums.end());

        return;
    }
};
