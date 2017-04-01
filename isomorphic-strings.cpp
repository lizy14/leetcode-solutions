class Solution {
public:
    typedef map<char, char> dict;
    bool isIsomorphic(string s, string t) {
        dict st, ts;
        int n = s.length();
        
        assert(n == t.length());
        for(int i=0; i<n; i++){
            char _s = s[i];
            char _t = t[i];
            auto _st = st.find(_s);
            auto _ts = ts.find(_t);
            if(_st != st.end()){
                if(_t != _st->second){
                    return false;
                }
            }
            if(_ts != ts.end()){
                if(_s != _ts->second){
                    return false;
                }
            }
            ts[_t] = _s;
            st[_s] = _t;
        }
        return true;
    }
};
