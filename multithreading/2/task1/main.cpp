#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <future>

template<typename It, typename Func>
void for_each(It first, It last, const Func &func) {
    for (It i = first; i != last; ++i) {
        *i = func(*i);
    }
}

template<typename It, typename Func>
void parallel_for_each(int num_threads, It first, It last, const Func &func) {
    int interval_size = std::distance(first, last);
    if (interval_size < num_threads) {
        num_threads = interval_size;
    }
    int elements_on_thread = (interval_size % num_threads == 0) ? interval_size / num_threads : 1 + interval_size /
                                                                                                    num_threads;
    std::vector<std::future<void>> futures;
    for (int i = 0; i < num_threads; ++i) {
        It interval_first = std::next(first, i * elements_on_thread);
        It interval_last = std::next(first, std::min(interval_size,
                                                     static_cast<int>(std::distance(first, std::next(first, (i + 1) *
                                                                                                            elements_on_thread)))));
        if (std::distance(interval_first, interval_last) > 0) {
            futures.push_back(
                    std::async(std::launch::async, for_each<It, Func>, interval_first, interval_last, std::cref(func)));
        }
    }
    for (auto &f: futures) {
        f.get();
    }
}

int square(int x) {
    return x * x;
}

template<typename C>
void print_container(const C &c) {
    for (const auto &el: c) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v{2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::list<int> l{2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::deque<int> d{2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int num_threads = std::thread::hardware_concurrency();
    parallel_for_each(num_threads, std::next(v.begin(), 1), std::next(v.begin(), 9), square);
    parallel_for_each(num_threads, l.begin(), std::next(l.begin(), 5), square);
    parallel_for_each(num_threads, d.begin(), d.end(), square);

    print_container(v);
    print_container(l);
    print_container(d);
}