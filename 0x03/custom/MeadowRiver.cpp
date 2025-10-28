#include <algorithm>
#include <array>
#include <iostream>
#include <stdexcept>
#include <ostream>
#include <vector>

class polynom {
    std::vector<double> coefficients;
public:
    explicit polynom(const unsigned int degree) : coefficients(degree) {}
    polynom(const std::vector<double> &pCoefficients) : coefficients(pCoefficients){}
    ~polynom() = default;

    [[nodiscard]] double eval(const double x) const {
        double result = 0;
        for (int i = 0; i < getDegree(); ++i)
            result = result * x + coefficients[i];
        return result;
    }

    [[nodiscard]] double at(const unsigned int i) const {
        if (i >= coefficients.size()) throw std::out_of_range("polynom index out of range");
        return coefficients[i];
    }

    [[nodiscard]] unsigned int getDegree() const {
        return coefficients.size();
    }

    void setCoef(const unsigned int i, const double new_coef) {
        if (i >= coefficients.size()) throw std::out_of_range("polynom index out of range");
        coefficients[i] = new_coef;
    }
};

polynom operator+(const polynom& lhs, const polynom& rhs) {
    const unsigned int newDegree = std::max(lhs.getDegree(), rhs.getDegree());
    polynom tmp(newDegree);
    for (int i = 1; i <= newDegree; ++i) {
        double newCoef = 0;
        if (lhs.getDegree() >= i) newCoef += lhs.at(lhs.getDegree()-i);
        if (rhs.getDegree() >= i) newCoef += rhs.at(rhs.getDegree()-i);
        tmp.setCoef(newDegree - i, newCoef);
    }

    return tmp;
}

std::ostream & operator<<(std::ostream &ostr, const polynom &p) {
    for(int i = 0; i < p.getDegree(); ++i) {
        const unsigned int power = p.getDegree() - i - 1;
        const double coef = p.at(i);

        if (coef == 0) continue;
        if (coef > 0 && i!=0) ostr << "+";
        if (power == 0) ostr << coef;
        else if (power == 1) ostr << coef << "x";
        else ostr << coef << "x^" << power;
    }
    return ostr;
}

int main() {
    const polynom poly1{{1, 0, 0}};
    std::cout << poly1 << " at " << 3 << " = " << poly1.eval(3) << std::endl;

    const polynom poly2{{3, -5, 7, 2}};
    std::cout << poly2 << " at " << 3<<" = " << poly2.eval(3) << std::endl;

    const polynom poly3 = poly1 + poly2;
    std::cout << poly3 << " at " << 3 << " = " << poly3.eval(3) << std::endl;
}

