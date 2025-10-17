#include <iostream>

int main() {
    std::cout << "Please enter a number: ";
    int n;
    std::cin >> n;
    std::cout << "Now enter a character: ";
    char c;
    std::cin >> c;

    const bool isBigger = n > 0;
    const bool isUpper = std::isupper(c);

    std::cout << "The number was " <<(isBigger?"":"not ") << "greater than 0";
    std::cout << " and the character is "<< (isUpper ? "":"not ") << "in upper case"<< std::endl;
    return 0;
}
