class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        unordered_map<int, int> map;
        for(auto i=0u; i<nums.size(); i++){
            map[nums[i]] = i;
        }
        for(auto i=0u; i<nums.size(); i++){
            int gap = target - nums[i];
            int gapId;
            auto gapIt = map.find(gap);
            if(gapIt != map.end() && (gapId=((*gapIt).second))>i){
                sol.push_back(i);
                sol.push_back(gapId);
                return sol;
            }
        }
        return sol;
    }
};
