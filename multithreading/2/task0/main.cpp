#include <vector>
#include <future>
#include <thread>
#include <iostream>

void find_minimal_element_pos(const std::vector<int> &v, int start, int stop, std::promise<int> &&pos) {
    int min_index = start;
    int min_value = v[start];
    for (int i = start + 1; i < stop; ++i) {
        if (v[i] < min_value) {
            min_index = i;
            min_value = v[i];
        }
    }
    pos.set_value(min_index);
}

void selection_sort(std::vector<int> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        std::promise<int> pos;
        std::future<int> pos_future{pos.get_future()};
        std::thread th{find_minimal_element_pos, std::cref(v), i, v.size(), std::move(pos)};
        th.detach();
        int min_index{pos_future.get()};
        std::swap(v[i], v[min_index]);
    }
}

int main() {
    std::vector<int> x{5, 7, 3, 1, 4, 8, 2, 9, 6};
    selection_sort(x);
    for (const auto &elem: x) {
        std::cout << elem << " ";
    }
}