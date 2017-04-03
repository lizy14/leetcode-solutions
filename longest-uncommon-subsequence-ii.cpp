class Solution {
public:
    int findLUSlength(vector<string>& strs){
        return bruteForce(strs);
    }
    
    int bruteForce(vector<string>& strs) {
        unordered_map<string, int> dict;
        for(auto str: strs){
            subsequences(str, dict);
        }
        int result = -1;
        for(auto e: dict){
            if(e.second == 1){
                int candidate = e.first.length();
                result = max(result, candidate);
            }
        }
        return result;
    }
    
    void subsequences(string& str, unordered_map<string, int>& dict){
        int p = 1 << str.length();
        int n = str.length();
        for(int i=0; i<p; i++){
            string subsequence = "";
            for(int j=0; j<n; j++){
                if((i >> j) & 1){
                    subsequence.push_back(str[j]);
                }
            }
            dict[subsequence] += 1;
        }
    }

};
