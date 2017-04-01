class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        vector<string> words{
            istream_iterator<string>{iss},
            istream_iterator<string>{}
        };
        if(pattern.size() != words.size()){
            return false;
        }
        map<char, string> dictcs;
        map<string, char> dictsc;
        for(int i=0; i<pattern.size(); i++){
            
            char c = pattern[i];
            string s = words[i];
            
            auto searchcs = dictcs.find(c);
            if(searchcs != dictcs.end()){
                if(s != searchcs->second){
                    return false;
                }
            }
            
            auto searchsc = dictsc.find(s);
            if(searchsc != dictsc.end()){
                if(c != searchsc->second){
                    return false;
                }
            }
            dictcs[c] = s;
            dictsc[s] = c;
        }
        return true;
    }
};
