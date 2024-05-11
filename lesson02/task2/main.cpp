#include <vector>
#include <algorithm>
#include <iostream>

class divisible_by_three {
public:
    void operator()(int n) {
        if (n % 3 == 0) {
            sum_ += n;
            ++count_;
        }
    }

    int get_sum() {
        return sum_;
    }

    int get_count() {
        return count_;
    }

private:
    int sum_ = 0;
    int count_ = 0;
};

int main() {
    std::vector<int> v{4, 1, 3, 6, 25, 54};
    divisible_by_three t = std::for_each(v.begin(), v.end(), divisible_by_three());
    std::cout << t.get_sum() << std::endl;
    std::cout << t.get_count() << std::endl;
}