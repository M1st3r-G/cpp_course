#include <cmath>
#include <iostream>
#include <string>

void cut(double &d, double &d2) {
    d = floor(d);
    d2 = floor(d);
}

void rotate(std::string &a, std::string &b, std::string &c) {
    std::swap(a, b);
    std::swap(b, c);
}

int main() {
    double d{10.127123};
    double d2{1012.7123};
    std::cout << "Original: " << d << ", cut: ";
    cut(d, d2);
    std::cout << d <<  std::endl;

    std::string a{" !"};
    std::string b{"Hallo"};
    std::string c{" Welt"};
    std::cout << "Original: "<< a << b<<c<<std::endl;
    rotate(a, b, c);
    std::cout << "Modified: "<< a << b<<c<<std::endl;
}
