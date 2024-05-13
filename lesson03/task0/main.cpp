#include <map>
#include <string>
#include <set>
#include <iostream>

int main() {
    std::map<char, int> symb_freq;
    std::string word = "Hello, world!";

    for (const auto &c: word) {
        ++symb_freq[c];
    }
    std::map<int, std::set<char>, std::greater<>> freq_symb;

    for (const auto &[symb, freq]: symb_freq) {
        freq_symb[freq].insert(symb);
    }

    for (const auto &[freq, symbols]: freq_symb) {
        for (const auto &symbol: symbols) {
            std::cout << symbol << ": " << freq << std::endl;
        }
    }
}