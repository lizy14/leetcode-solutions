class Solution {
    
    static int row(char c){
        vector<string> rows;
        rows.push_back("qwertyuiop");
        rows.push_back("asdfghjkl");
        rows.push_back("zxcvbnm");
        
        c = tolower(c);
        
        for(int i=0; i<rows.size(); ++i){
            if(rows[i].find(c) != rows[i].npos){
                return i;
            }
        }
        
    }
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for(auto& word: words){
            if(word.empty()){
                continue;
            }
            int a = row(word[0]);
            for(auto c : word){
                if(a != row(c)){
                    goto outer_continue;
                }
            }
            result.push_back(word);
            outer_continue:
            ;
        }
        return result;
        
    }
};
