class Solution {
public:
    int findDuplicate(vector<int>& nums) {
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
