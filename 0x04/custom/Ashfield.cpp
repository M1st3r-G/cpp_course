#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>

struct book {
    std::string author;
    std::string title;
};

std::ostream& operator<<(std::ostream & ostream, const book & book) {
    ostream <<"\""<< book.author << "\" by \"" << book.title<<"\"";
    return ostream;
}

void fill_catalogue(std::pmr::unordered_map<std::string, book>& catalogue) {
    catalogue.insert({"978-44245381XX", {"Walter Moers","The 13 1/2 Lives of Captain Bluebear"}});
    catalogue.insert({"978-1846558245", {"Yuval Noah Harari","Sapiens: A Brief History of Humankind"}});
    catalogue.insert({"978-0553386790", {"Frank Herbert", "Dune"}});
    catalogue.insert({"978-0261103573", {"J.R.R. Tolkien", "The Lord of the Rings: The Fellowship of the Ring"}});
    catalogue.insert({"978-0747532743", {"J.K. Rowling", "Harry Potter and the Philosopher's Stone"}});
    catalogue.insert({"978-0451524935", {"George Orwell", "1984"}});
    catalogue.insert({"978-0060850524", {"Neil Gaiman", "American Gods"}});
    catalogue.insert({"978-0385537858", {"Andy Weir", "The Martian"}});
    catalogue.insert({"978-0553573404", {"George R.R. Martin", "A Game of Thrones"}});
    catalogue.insert({"978-0345391803", {"Douglas Adams", "The Hitchhiker's Guide to the Galaxy"}});
    catalogue.insert({"978-0062316097", {"Harper Lee", "To Kill a Mockingbird"}});
    catalogue.insert({"978-0061120084", {"Aldous Huxley", "Brave New World"}});
    catalogue.insert({"978-0345803481", {"Ernest Cline", "Ready Player One"}});
    catalogue.insert({"978-0307474278", {"Cormac McCarthy", "The Road"}});
    catalogue.insert({"978-1524763169", {"Margaret Atwood", "The Handmaid's Tale"}});
    catalogue.insert({"978-0141182803", {"F. Scott Fitzgerald", "The Curious Case of Benjamin Button and Other Jazz Age Stories"}});
    catalogue.insert({"978-0345535528", {"Patrick Rothfuss", "The Name of the Wind: The Kingkiller Chronicle, Day One"}});
}

int main() {
    using catalogue_t = std::pmr::unordered_map<std::string, book>;
    catalogue_t catalogue;
    fill_catalogue(catalogue);
    std::cout << "Long titled books:\n";
    for (const auto& [isbn, book] : catalogue) {
        if (book.title.length() > 40) std::cout << book << "\n";
    }
    std::cout <<std::endl;
}
