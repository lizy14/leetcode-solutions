class Solution {
    class Complex {
    public:
        int real;
        int imaginary;
        Complex(const string& s) {
            auto plus = s.find('+');
            real = stoi(s);
            imaginary = stoi(s.substr(plus + 1));
        }
        Complex() {}
        operator string() const {
            ostringstream s;
            s << real << '+' << imaginary << 'i';
            return s.str();
        }
    };
    Complex multiply(Complex x, Complex y) {
        auto a = x.real;
        auto b = x.imaginary;
        auto c = y.real;
        auto d = y.imaginary;
        Complex r;
        r.real = a * c - b * d;
        r.imaginary = b * c + a * d;
        return r;
    }
public:
    string complexNumberMultiply(string a, string b) {
        return multiply(a, b);
    }
};
