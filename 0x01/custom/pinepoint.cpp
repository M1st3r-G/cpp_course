#include <iostream>

bool isPrim(int i) {
    if (i <= 1) return false;
    // Dont use full range
    for (int n = 2; n < i; n++)
        if (i % n == 0) return false;
    return true;
};

int main() {
    int c;
    std::cin >> c;
    std::cout << isPrim(c);
}
