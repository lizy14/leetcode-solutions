class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string str;
        int i=0;
        while(1){
            auto c = common(i, strs);
            if(c)
                str.push_back(c);
            else
                break;
            i++;
        }
        return str;
    }
    char common(int i, vector<string>& strs){
        if(i >= strs[0].length())
            return 0;
        auto c = strs[0][i];
        int n = strs.size();
        for(int j=1; j<n; j++){
            if(i >= strs[j].length() || (strs[j][i]) != c)
                return 0;
        }
        return c;
    }
    
};
