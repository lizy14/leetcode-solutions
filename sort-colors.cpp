class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counters[3] = {0, 0, 0};
        for(auto n : nums){
            counters[n] ++;
        }
        int subscript = 0;
        for(auto j=0; j<3; j++){
            for(auto i=0; i<counters[j]; i++){
                nums[subscript++] = j;
            }
        }
    }
};
