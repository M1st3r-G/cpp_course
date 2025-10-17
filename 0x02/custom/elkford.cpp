#include <iostream>
#include <ostream>
constexpr int dim{3};

struct polynom {
    double coeffs[dim];
};

std::ostream & operator<<(std::ostream &ostr, const polynom &p) {
    //ostr << p.coeffs[0] << "x^2 + " << p.coeffs[1] << "x + " << p.coeffs[2];
    for(int i = 0; i < dim; ++i) {
        int power = dim - i - 1;
        ostr << p.coeffs[i] << "x^" << power;
        if (i < dim - 1) ostr << " + ";
    }
    return ostr;
}

double eval(const double x, const polynom &poly) {
    return poly.coeffs[2] + poly.coeffs[1]*x + poly.coeffs[0]*x*x;
}

int main() {
    constexpr polynom poly1{1, 0, 0};
    std::cout << poly1 << " at " << 3 << " = " << eval(3, poly1) << std::endl;

    constexpr polynom poly2{3, -5, 7};
    std::cout << poly2 << " at " << 3<<" = " << eval(3, poly2) << std::endl;
}
