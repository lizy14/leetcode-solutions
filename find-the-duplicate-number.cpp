class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast;
        slow = nums[0];
        fast = nums[nums[0]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    int findDuplicateBruteForce(vector<int>& nums) {
        auto n = nums.size();
        for(auto x: nums){
            int counter = 0;
            for(auto y: nums){
                counter += (x==y);
            }
            if(counter > 1){
                return x;
            }
        }
        throw 233;
    }
};
