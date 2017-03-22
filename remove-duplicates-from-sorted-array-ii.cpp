class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto n = nums.size();
        if(n == 0){
            return 0;
        }
        int last = nums[0];
        int counter = 1;
        int read = 1;
        int write = 1;
        for(; read < n; read ++, write ++){
            int current = nums[read];
            if(current == last){
                counter += 1;
                if(counter > 2){
                    write --; // revert
                }
            }else{
                last = current;
                counter = 1;
            }
            nums[write] = current;
        }
        return write;
    }
};
