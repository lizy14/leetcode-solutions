class Solution {
public:
    string frequencySort(string s) {
        vector<int> counter(256); // map from char
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
