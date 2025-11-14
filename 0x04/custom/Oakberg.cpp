#include <iostream>
#include <ostream>
#include <vector>

int main() {
    int tmpa[]{2, 3, 5, 7, 11};
    std::vector tmpv{2, 3, 5, 7, 11};

    std::cout << "Ausgabe des Arrays: ";
    for (const int a : tmpa) {
        std::cout << a << ", ";
    }

    std::cout << "\nAusgabe des Vectors: ";
    for (const int a : tmpv) {
        std::cout << a << ", ";
    }

    for (auto &a : tmpa) {
        a*=2;
    }
    for (auto &a : tmpv) {
        a*=2;
    }

    std::cout << "\nErgebnisse des Arrays: ";
    auto foundA = std::ranges::find(tmpa, 6);
    for (int i = 3; i; --i) {
        if (foundA != std::ranges::end(tmpa)) {
            // Wenn Gefunden:
            std::cout << *foundA << ", ";
        }
        ++foundA;
        // nächstes
    }

    std::cout << "\nErgebnisse des Vectors: ";
    auto foundV = std::ranges::find(tmpv, 6);
    for (int i = 3; i; --i) {
        if (foundV != std::ranges::end(tmpv)) std::cout << *foundV << ", ";
        ++foundV;
    }

    std::cout << std::endl;
}
