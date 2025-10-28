#include <iostream>
#include <ostream>
#include <string>
#include <utility>

class contact {
    std::string name;
    unsigned int age;
public:
    contact() : age(0) {} // String als Klasse automatisch leer
    contact(std::string  name, const unsigned int age) : name(std::move(name)), age(age) {}
    contact(const contact &other) = default;
    ~contact() = default;

    [[nodiscard]] std::string getName() const { return name; }
    [[nodiscard]] unsigned int getAge() const { return age; }

    void setAge(const unsigned int pAge) { age = pAge; }
    void setName(const std::string &pName) { name = pName; }

    friend std::ostream & operator<<(std::ostream &os, const contact &obj) {
        return os << obj.name << " (" << obj.age<<")";
    }
};

int main() {
    contact c{};
    std::cout << c;
    c.setName("Hallo");
    std::cout << c;
    contact c2{"Hans", 212};
    std::cout << c2;
    c2.setAge(12);
    std::cout << c2;
}

