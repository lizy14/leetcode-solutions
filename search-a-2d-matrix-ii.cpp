class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        if(h == 0){
            return false;
        }
        int w = matrix[0].size();
        if(w == 0){
            return false;
        }
        
        int x = 0;
        int y = h - 1;
        
        while(x < w && y >= 0){
            int e = matrix[y][x];
            if(e > target){
                y --;
            }else if(e < target){
                x ++;
            }else{
                return true;
            }
        }
        return false;
    }
};
