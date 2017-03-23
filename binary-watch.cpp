class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        int total = (1 << 10) - 1;
        for(int i=0; i<total; i++){
            if(countOne(i) == num){
                try{
                    result.push_back(translate(i));
                }catch(...){
                    ;
                }
            }
        }
        return result;
    }
    int countOne(int x){
        int s = 0;
        while(x != 0){
            if(x & 1){
                s ++;
            }
            x >>= 1;
        }
        return s;
    }
    string translate(int x){
        int hour = x >> 6;
        int mask = (1 << 6) - 1;
        int minute = x & mask;
        if(hour >=12 || minute >= 60){
            throw 233;
        }
        stringstream result;
        result << hour << ":";
        if(0 <= minute && minute <= 9){
            result << "0";
        }
        result << minute;
        return result.str();
    }
};
