class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	auto n = nums.size();
    
    	for (int i = 0; i < n; ++i) {
    		auto& num = nums[i];
    
    		while (num > 0 && num <= n && nums[num - 1] != num) {
    			std::swap(num, nums[num - 1]);
    		}
    	}
    
    	for (int i = 0; i < n; ++i)
    		if (nums[i] != i + 1)
    			return i + 1;
    
    	return n + 1;
    }
};
