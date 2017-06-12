class Solution {
public:
    string reverseVowels(string s) {
        auto n = s.length();
        auto a = n - n, b = n - 1;
        while(true){
            while(!isVowel(s[a]) && a < n){
                ++a;
            }
            while(!isVowel(s[b]) && b > 0){
                --b;
            }
            cout << a << ',' << b << endl;
            
            if(a >= n || b <= 0 || a >= b){
                break;
            }
            swap(s[a], s[b]);
            ++a;
            --b;
        }
        return s;
    }
    bool isVowel(char c){
        const string vowels = "aeiouAEIOU";
        return vowels.find(c) != string::npos;
    }
};
