#include <iostream>
constexpr int size{3};

class stack_full_exception : public std::exception {
///public:
///    const char* what() const noexcept override {
///        return "Stack is full";
///    }
};

struct stack {
    int next = 0;
    int values[size];

    void push(const int value) {
        if (next >= size) {
            std::cout << "The stack is full";
            throw stack_full_exception();
        }

        values[next++] = value;
    }

    int pop() {
        if (next <= 0) {
            std::cout << "The stack is empty\n";
            // Besser, fehler werfen.
            return -1;
        }

        return values[--next];
    }
};


int main() {
    stack t{};
    t.push(1);
    t.push(2);
    t.push(3);
    try {
        t.push(4);
        std::cout << "The Stack should have been full\n";
    } catch (const stack_full_exception &e) {
        //std::cout << "Caught exception: " << e.what() << '\n';
        std::cout << "The stack was full\n";
    }

    std::cout << t.pop() << std::endl;
}
