#include <iostream>
#include <ostream>

class fraction {
    int numerator;
    int denominator;

public:
    fraction(const int pNum, const int pDenom) : numerator(pNum), denominator(pDenom) {}
    // This doesn't really make sense without context, could also delete
    fraction() : numerator(1), denominator(1) {}
    fraction(const fraction &other) = default;
    ~fraction() = default;

    void setNumerator(const int pNum) {
        numerator = pNum;
    }

    void setDenominator(const int pDenom) {
        if (pDenom == 0) throw std::invalid_argument("pDenom cannot be zero");
        denominator = pDenom;
    }

    friend std::ostream & operator<<(std::ostream &ostr, const fraction &obj) {
        return ostr << "(" << obj.numerator << " | " << obj.denominator << ")";
    }
};

int main() {
    fraction frac1{2, 3};
    const fraction frac2{};
    std::cout << frac2 << std::endl;
    std::cout << frac1;
    frac1.setNumerator(1);
    std::cout << frac1;
    fraction frac3{frac1};
    frac3.setDenominator(2);
    std::cout << frac3 << std::endl;
}

