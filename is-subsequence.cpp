class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < t.length() && j < s.length()){
            j += (s[j] == t[i]);
            i++;
        }        
        return j == s.length();
    }
};
