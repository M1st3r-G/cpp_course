#include <iostream>
#include <ostream>

bool divmod(const int n, const int p, int *pdiv, int *pmod) {
    *pdiv = 0;
    *pmod = 0;
    if (p == 0) return false;
    *pdiv = n/p;
    *pmod = n%p;
    return true;
}

int main() {
    int div;
    int mod;

    divmod(13, 0, &div, &mod);
    std::cout <<" 13 divmod 0: div = " << div << ", mod =" << mod << std::endl;
    divmod(13, 4, &div, &mod);
    std::cout <<" 13 divmod 4: div = " << div << ", mod =" << mod << std::endl;
}
