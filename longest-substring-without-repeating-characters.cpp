class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int start = 0;
        int maxLength=0;
        for(int i=0u; i<s.size(); i++){
            maxLength=max(maxLength, i-start);
            if(last[s[i]]>=start){
                start=last[s[i]]+1;
            }
            last[s[i]]=i;
        }
        maxLength = max(maxLength, (int)s.size()-start);
        return maxLength;
    }
};
