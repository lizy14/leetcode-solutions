class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end() - k);
        std::reverse(nums.end() - k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};
