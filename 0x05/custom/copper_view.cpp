#include <iostream>
#include <ostream>

int main() {
    int a{69};
    float b{4.2};
    int *pa = &a;
    float* pb = &b;

    *pa = 96;
    *pb = 2.4;

    std::cout << "pa="<<pa<< ", *pa="<<*pa<<", a= "<<a<<std::endl;
    std::cout << "pb="<<pb<< ", *pa="<<*pb<<", b= "<<b<<std::endl;

    int* *ppa{&pa};
    std::cout << "a = "<<**ppa<<std::endl;
}
