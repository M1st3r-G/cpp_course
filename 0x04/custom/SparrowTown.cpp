#include <iostream>
#include <ostream>

template<typename T1, typename T2>
class general_point {
    T1 x;
    T2 y;
public:
    general_point(const T1 x, const T2 y) : x(x), y(y) {}
    general_point(const general_point &other) = default;
    ~general_point() = default;

    [[nodiscard]] T1 getX() const { return x; }
    [[nodiscard]] T2 getY() const { return y; }

    void setX(const T1 pX) {x = pX; }
    void setY(const T2 pY) {y = pY; }

    friend std::ostream & operator<<(std::ostream &os, const general_point &obj) {
        return os << "(" << obj.x<< "|" << obj.y<<")";
    }
};

int main() {
    general_point frac1{2, 3};
    const general_point<int, std::string> frac2{0,"jasdkl"};
    std::cout << frac2 << std::endl;
    std::cout << frac1;
    frac1.setX(1);
    std::cout << frac1;
    general_point frac3{frac1};
    frac3.setY(2);
    std::cout << frac3 << std::endl;
}