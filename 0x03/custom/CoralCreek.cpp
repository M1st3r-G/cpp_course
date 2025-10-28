#include <iostream>
#include <ostream>
template <typename T> class MyOptional {
    bool isSet;
    T value;
    int version;
public:
    MyOptional() : isSet(false), version(0) {}
    MyOptional(const T value) : isSet(true), value(value), version(1) {}
    // Could also just copy state and value only if necessary
    MyOptional(const MyOptional &other) = default;
    ~MyOptional() {std::cout << "~OptionalInt()" << std::endl;}

    [[nodiscard]] bool hasValue() const {return isSet;}
    [[nodiscard]] T getValue() const {
        if (!isSet) throw std::runtime_error("Not set");
        return value;
    }

    [[nodiscard]] T getValueOr(const T fallback) const {
        return isSet ? value : fallback;
    }

    void setValue(const T newValue) {
        isSet = true;
        value = newValue;
        ++version;
    }

    void clear() {
        isSet = false;
        version = 0;
    }

    friend std::ostream & operator<<(std::ostream &os, const MyOptional &obj) {
        if (obj.hasValue()) os << obj.getValue();
        else os << "none";
        os << "(Iteration: " << obj.version << ")";
        return os;
    }

    friend bool operator==(const MyOptional &lhs, const MyOptional &rhs) {
        if (lhs.hasValue() && rhs.hasValue())
            return lhs.getValue() == rhs.getValue();
        return !lhs.hasValue() && !rhs.hasValue();
    }

    friend bool operator!=(const MyOptional &lhs, const MyOptional &rhs) {
        return !(lhs == rhs);
    }
};

int main() {
    MyOptional<int> opt1;
    std::cout << "opt1: " << opt1 << std::endl; // Erwartet: none(Iteration: 0)

    opt1.setValue(42);
    std::cout << "opt1: " << opt1 << std::endl; // Erwartet: 42(Iteration: 1)

    std::cout << "opt1 has value? " << (opt1.hasValue() ? "yes" : "no") << std::endl; // yes
    std::cout << "opt1 value: " << opt1.getValue() << std::endl; // 42
    std::cout << "opt1 fallback: " << opt1.getValueOr(99) << std::endl; // 42

    opt1.setValue(100);
    std::cout << "opt1 after update: " << opt1 << std::endl; // 100(Iteration: 2)

    opt1.clear();
    std::cout << "opt1 after clear: " << opt1 << std::endl; // none(Iteration: 0)

    MyOptional<int> opt2(123);
    std::cout << "opt2: " << opt2 << std::endl; // 123(Iteration: 1)

    std::cout << "opt1 == opt2? " << (opt1 == opt2 ? "yes" : "no") << std::endl; // no
    std::cout << "opt1 != opt2? " << (opt1 != opt2 ? "yes" : "no") << std::endl; // yes

    MyOptional<int> opt3(123);
    std::cout << "opt2 == opt3? " << (opt2 == opt3 ? "yes" : "no") << std::endl; // yes


    // Und dann drei mal der Dtor.
    return 0;
}
