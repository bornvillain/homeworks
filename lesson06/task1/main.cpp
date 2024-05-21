#include <string>
#include <algorithm>
#include <iostream>

class big_integer {
public:
    big_integer()
            : number_("0") {}

    explicit big_integer(std::string &&number)
            : number_(std::move(number)) {}

    big_integer(const big_integer &other) = default;

    big_integer(big_integer &&other) noexcept
            : number_(std::move(other.number_)) {}

    big_integer &operator=(const big_integer &rhs) {
        big_integer tmp = big_integer(rhs);
        std::swap(tmp.number_, number_);
        return *this;
    }

    big_integer &operator=(big_integer &&rhs) noexcept {
        std::swap(rhs.number_, number_);
        return *this;
    }

    big_integer operator+(const big_integer &rhs) const {
        std::string result;
        auto it1 = (number_.size() > rhs.number_.size() ? rhs.number_.rbegin() : number_.rbegin());
        auto it2 = (number_.size() > rhs.number_.size() ? number_.rbegin() : rhs.number_.rbegin());

        int common_digits = std::min(number_.size(), rhs.number_.size());
        int remaining_digits = std::max(number_.size(), rhs.number_.size());
        bool overflow = false;
        for (int i = 0; i < common_digits; ++i) {
            int place_number = (*it1 - '0') + (*it2 - '0');
            result.push_back(calculate_digit(place_number, overflow));
            it1++;
            it2++;
            --remaining_digits;
        }
        while (remaining_digits != 0) {
            int place_number = *it2 - '0';
            result.push_back(calculate_digit(place_number, overflow));
            it2++;
            --remaining_digits;
        }
        if (overflow) {
            result.push_back(static_cast<char>(1 + '0'));
        }
        std::reverse(result.begin(), result.end());
        return big_integer(std::move(result));
    }

    big_integer operator+=(const big_integer &rhs) {
        return *this = rhs + *this;
    }

    const std::string &get_number() const {
        return number_;
    }

    big_integer operator*(int value) const {
        big_integer result;
        for (int i = 0; i < value; ++i) {
            result += *this;
        }
        return result;
    }

    big_integer operator*=(int value) {
        return *this = *this * value;
    }

private:
    char calculate_digit(int place_number, bool &overflow) const {
        if (overflow) {
            ++place_number;
        }
        overflow = false;
        if (place_number > 9) {
            overflow = true;
            place_number -= 10;
        }
        return static_cast<char>(place_number + '0');
    }

    std::string number_;
};

std::ostream &operator<<(std::ostream &stream, const big_integer &number) {
    for (const auto &digit: number.get_number()) {
        stream << digit;
    }
    return stream;
}

int main() {
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result;
}