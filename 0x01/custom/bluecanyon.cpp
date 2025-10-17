#include <iostream>

double pot(double base, int exp);

int main() {
    double b;
    int n;

    std::cout << "Enter a decimal number for the base: ";
    std::cin >> b;
    std::cout << "Enter a whole number for the exponent: ";
    std::cin >> n;

    std::cout <<"The Result is: "<< pot(b, n) << std::endl;
}

double pot(const double base, int exp) {
    double res{1};
    while (exp--) res *= base;
    //for(;--exp;) res *= base;
    return res;
}

