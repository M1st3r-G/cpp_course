#include <iostream>
#include <ostream>

class Node {
    int payload;
    Node *next;

public:
    explicit Node(const int payload) : payload(payload), next(nullptr) {}
    Node(const int value, Node *next) :payload(value), next(next) {}

    [[nodiscard]] int get_payload() const {return payload;}
    [[nodiscard]] Node *get_next() const {return next;}
};


int main() {
    Node n1{4};
    Node n2{3, &n1};
    Node n3{2, &n2};
    const Node root{1, &n3};

    const Node *current = &root;
    while (current != nullptr) {
        std::cout << current->get_payload() << std::endl;
        current = current->get_next();
    }
}
