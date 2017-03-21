class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        map<int, int> m;
        for(auto num: nums){
            m[num] ++;
        }
        for(auto it: m){
            if(it.second <= 1){
                result.push_back(it.first);
            }
        }
        return result;
    }
};
