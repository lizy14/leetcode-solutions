class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto num: nums){
            x ^= num;
        }
        int mask = x & -x; // least significant 1
        int a = 0, b = 0;
        for(auto num: nums){
            if(num & mask){
                a ^= num;
            }else{
                b ^= num;
            }
        }
        
        vector<int> result = {a, b};
        return result;
    }
    vector<int> singleNumberBruteForce(vector<int>& nums) {
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
