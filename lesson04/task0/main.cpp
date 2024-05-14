#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

void make_unique(std::vector<int> &v) {
    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());
}

std::vector<int> split_into_numbers(const std::string &line) {
    std::vector<int> result;
    std::istringstream iss(line);
    std::string s;
    while (iss >> s) {
        result.push_back(std::stoi(s));
    }
    return result;
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::vector<int> test_vector = split_into_numbers(line);
    make_unique(test_vector);
    for (const auto &item: test_vector) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}