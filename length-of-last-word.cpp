class Solution {
public:
    int lengthOfLastWord(string s) {
        while(!s.empty() && s.back() == ' '){
            s.pop_back();
        }
        auto l = s.find_last_of(' ');
        auto n = s.length();
        if(l == s.npos){
            return n;
        }
        return n - l - 1;
    }
};
