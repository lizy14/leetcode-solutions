class Solution {
public:
    int countSegments(string s) {
        bool flag = true; // last char is space?
        int count = 0;
        for(auto c : s){
            bool new_flag = c == ' ';
            if(!flag && new_flag){
                count ++;
            }
            flag = new_flag;
        }
        if(!flag){
            count ++;
        }
        return count;
    }
};
