class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        for(int i=2; i<=rowIndex; i++){
            // update to i-th row
            for(int j=i-1; j>=1; j--){
                row[j] = row[j] + row[j-1];
            }
        }
        return row;
    }
};
