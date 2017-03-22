class Solution {
public:
    typedef vector<int> line;
    vector<vector<int>> generate(int numRows) {
        
        vector<line> lines;
        if(numRows < 1){
            return lines;
        }
        line l = {1};
        lines.push_back(l);
        
        for(int i=1; i<numRows; i++){
            
            line current(i+1);
            current[0] = 1;
            current[i] = 1;
            
            line& last = lines[i - 1];
            
            for(int j=1; j<i; j++){
                current[j] = last[j-1] + last[j];
            }
            
            lines.push_back(current);
        }
        
        return lines;
    }
};
