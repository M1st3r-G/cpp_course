#include <iostream>
#include <ostream>

class point {
    double x, y;
public:
    point() : x(0), y(0) {}
    point(const double x, const double y) : x(x), y(y) {}
    point(const point &other) = default;
    ~point() = default;

    [[nodiscard]] double getX() const { return x; }
    [[nodiscard]] double getY() const { return y; }

    void setX(const double pX) {x = pX; }
    void setY(const double pY) {y = pY; }

    friend std::ostream & operator<<(std::ostream &os, const point &obj) {
        return os << "(" << obj.x<< "|" << obj.y<<")";
    }
};

int main() {
    point frac1{2, 3};
    const point frac2{};
    std::cout << frac2 << std::endl;
    std::cout << frac1;
    frac1.setX(1);
    std::cout << frac1;
    point frac3{frac1};
    frac3.setY(2);
    std::cout << frac3 << std::endl;
}