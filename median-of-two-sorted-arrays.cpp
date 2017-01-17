class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums(nums1.size()+nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
        auto n = nums.size();
        if(n % 2 != 0)
            return nums[(n-1)/2];
        else
            return (nums[n/2]+nums[n/2-1]+0.)/2;
    }
};
