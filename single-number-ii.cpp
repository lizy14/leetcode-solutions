class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::map<int, int> m;
        for(auto num: nums){
            m[num] ++;
        }
        for(auto it: m){
            if(it.second == 1){
                return it.first;
            }
        }
        throw 233;
    }
};
