class Solution {
public:
    string frequencySort(string s) {
        int counter[sizeof(char) * 256] = {0}; // unordered_map<char, int>
        for(auto c: s) {
            counter[c] ++;
        }
        sort(s.begin(), s.end(), [&counter](char a, char b) {
            auto ac = counter[a];
            auto bc = counter[b];
            return ac == bc? a > b : ac > bc;
        });
        return s;
        
    }
};
