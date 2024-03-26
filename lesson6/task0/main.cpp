#include <iostream>
#include <string>
#include <exception>

class bad_length : public std::exception {
public:
    const char *what() const noexcept override {
        return "You have entered a word of prohibited length! Goodbye";
    }
};

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw bad_length();
    }
    return str.size();
}

int main() {

    int forbidden_length;
    std::string word;
    std::cout << "Enter forbidden length: ";
    std::cin >> forbidden_length;
    while (true) {
        std::cout << "Enter a word: ";
        std::cin >> word;

        try {
            std::cout << "The length of the word " << word << " is " << function(word, forbidden_length) << std::endl;
        }
        catch (const bad_length &ex) {
            std::cout << ex.what() << std::endl;
            break;
        }
        catch (...) {
            std::cout << "Unknown error" << std::endl;
        }
    }
}