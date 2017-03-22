class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto& row: matrix){
            if(searchRowWrapped(row, target)){
                return true;
            }
        }
        return false;
    }
    bool searchRowWrapped(vector<int>& row, int target){
        if(row.empty()){
            return false;
        }
        int start = *row.begin();
        int end = *(row.end() - 1);
        if(start > target || end < target){
            return false;
        }
        return searchRow(row, target);
    }
    bool searchRow(vector<int>& row, int target){
        auto n = row.size();
        if(n == 0){
            return false;
        }
        int l = 0, r = n - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            int x = row[m];
            if(x > target){
                r = m - 1;
            }else if(x < target){
                l = m + 1;
            }else{
                return true;
            }
        }
        return false;
    }
};
