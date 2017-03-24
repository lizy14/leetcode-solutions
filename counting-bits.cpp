class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        result[0] = 0;
        result[1] = 1;
        
        for(int i = 2; ; i *= 2){
            // i elements already filled
            for(int j = 0; j < i; j += 1){
                if(i + j > num){
                    return result;
                }
                result[i + j] = 1 + result[j];
            }
        }
    }
};
