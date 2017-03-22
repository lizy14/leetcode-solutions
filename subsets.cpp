class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        auto n = nums.size();
        int n_sets = 1 << n;
        for(int s = 0; s < n_sets; s ++){
            vector<int> set;
            auto bits = s;
            int j = 0;
            do{
                if(bits & 1){
                    set.push_back(nums[j]);
                }
                bits >>= 1;
            }while(j ++, bits > 0);
            sets.push_back(set);
        }
        return sets;
    }
};
