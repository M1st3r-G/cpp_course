#include <cstddef>
#include <iostream>

int main() {
    long test{0x22445566};
    std::byte *illegal = reinterpret_cast<std::byte *>(&test);
    illegal+= 3; //12;
    std::cout << "Previously: \t" << std::hex<<test << std::endl;
    *illegal = static_cast<std::byte>(0x11);
    std::cout << "After stuff: \t" << test << '\n';
}
