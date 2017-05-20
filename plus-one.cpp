class Solution {
    const static int BASE = 10;
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(auto it = digits.rbegin(); it != digits.rend(); ++it){
            auto& digit = *it;
            digit += carry;
            carry = digit / BASE;
            digit %= BASE;
        }
        if(carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
