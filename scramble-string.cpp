class Solution {
public:
    bool isScramble(string s1, string s2) {
        unordered_map<char, int> counter;
        if(s1.length() != s2.length()){
            return false;
        }
        if(s1 == s2){
            return true;
        }
        int n = s1.length();
        for(int i=0; i<n; ++i){
            counter[s1[i]] ++;
            counter[s2[i]] --;
        }
        for(auto p : counter){
            if(p.second != 0){
                return false;
            }
        }
        
        for(int i=1; i<n; ++i){
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))){
                return true;
            }
            if(isScramble(s1.substr(0, i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i))){
                return true;
            }
        }
        return false;
    }
};
