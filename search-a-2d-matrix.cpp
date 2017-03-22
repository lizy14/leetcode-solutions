class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto h = matrix.size();
        if(h == 0){
            return false;
        }
        auto w = matrix[0].size();
        if(w == 0){
            return false;
        }
        
        int l = 0, r = w * h - 1;
        
        while(l <= r){
            int m = l + (r - l) / 2;
            int x = matrix[m / w][m % w];
            if(x == target){
                return true;
            }else if(x > target){
                r = m - 1;
            }else/*if x < target*/{
                l = m + 1;
            }
        }
        
        return false;
    }
};
