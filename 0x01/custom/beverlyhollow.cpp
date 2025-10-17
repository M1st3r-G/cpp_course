#include <iostream>

int f_i(int n);

int main() {
    std::cout << "Please enter a whole number: ";
    int number;
    std::cin >> number;

    while (number-- > 0) {
        std::cout << number << "das ergebnis lautet: " << f_i(number) << std::endl;
    }
}

int f_i(const int n) {
    int a = 1;
    int b = 1;
    for (int i = 0; i < n; i++) {
        const int tmp = a+b;
        a=b;
        b=tmp;
    }
    return a;
}