#include <iostream>

int main() {
    constexpr int a{3};
    double values[a]{1.0, 2.0}; // working?

    values[2] = values[0] + values[1];
    std::cout << values[0] << values[1]<< values[2] << std::endl;

    double copy[a];
    //std::copy(values, values + a, copy);
    for (int i = 0; i < a; i++) {
        copy[i] = values[i];
    }

    std::cout << copy[0] << copy[1]<< copy[2] << std::endl;

}
