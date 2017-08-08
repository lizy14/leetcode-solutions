class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        if(n <= 1){
            return 1;
        }
        
        int result = n;
        vector<size_t> lookup = {0, 1};
        
        for(int i=1; i<n; ++i){
            vector<size_t> new_lookup = {i, i + 1};
            const char current_char = s[i];
            for(const auto& starting : lookup){
                if(starting == 0){
                    continue;
                }
                char& starting_char_candidate = s[starting - 1];
                
                if(starting_char_candidate == current_char){
                    result ++;
                    new_lookup.push_back(starting - 1);
                }
                
            }
            
            lookup = new_lookup;
        }
        
        return result;
        
    }
};
