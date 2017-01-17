class Solution {
public:
    int chr(char c){
        int _ = c - '0';
        if(_<0 || _>9)
            return -1;
        return _;
    }
    string trim(string s){
        string r;
        int a=0, b=s.length();
        while(s[a]==' ' && a<s.length())a++;
        while(s[b]==' ' && b>0)b--;
        return s.substr(a, b-a+1);
    }
    int myAtoi(string str) {
        str = trim(str);
        if(str.length()==0)
            return 0;
        int result=0;
        bool negative = (str[0]=='-');
        for(int i=0; i<str.length(); i++){
            if(i==0 && str[i]=='+') continue;
            if(i==0 && str[i]=='-') continue;
            if(chr(str[i])<0)
                return result*(negative?-1:1);
            if(result > INT_MAX/10 || (result == INT_MAX/10 && chr(str[i])>INT_MAX%10))
                return negative?INT_MIN:INT_MAX;
            result *= 10;
            result += chr(str[i]);
        }
        return result*(negative?-1:1);
    }
};
