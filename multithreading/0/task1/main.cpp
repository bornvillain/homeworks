#include <thread>
#include <vector>
#include <numeric>
#include <iostream>
#include <random>
#include <chrono>

std::vector<int> generate_random_vector(int size) {
    std::vector<int> vec;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);
    for (int i = 0; i < size; ++i) {
        vec.push_back(dis(gen));
    }
    return vec;
}

void partial_sum_two_vectors(const std::vector<int> &first, const std::vector<int> &second, std::vector<int> &result,
                             int start_index, int end_index) {
    int partial_sum = 0;
    for (int i = start_index; i < end_index; ++i) {
        partial_sum += first[i] + second[i];
    }
    result.push_back(partial_sum);
}

int sum_two_vectors_on_threads(int num_threads, const std::vector<int> &first, const std::vector<int> &second,
                               std::vector<int> &result, int total_elements) {
    std::vector<std::thread> threads;
    int elements_on_thread = (total_elements % num_threads == 0) ? total_elements / num_threads : 1 + total_elements /
                                                                                                      num_threads;
    for (int i = 0; i < num_threads; ++i) {
        int start = i * elements_on_thread;
        int end = std::min((i + 1) * elements_on_thread, total_elements);
        threads.push_back(
                std::thread(partial_sum_two_vectors, std::ref(first), std::ref(second), std::ref(result), start, end));
    }
    for (auto &t: threads) {
        t.join();
    }
    return std::accumulate(result.begin(), result.end(), 0);
}

int main() {
    std::cout << "Number of hardware cores: " << std::thread::hardware_concurrency << std::endl;
    std::vector<int> num_elements = {1000, 10000, 100000, 1000000};
    std::vector<int> num_threads = {2, 4, 8, 16};
    for (int i = 0; i < num_elements.size(); ++i) {
        std::cout << "Vector size: " << num_elements[i] << std::endl;
        std::vector<int> a = generate_random_vector(num_elements[i]);
        std::vector<int> b = generate_random_vector(num_elements[i]);
        for (int j = 0; j < num_threads.size(); ++j) {
            std::cout << "Number of threads: " << num_threads[j] << std::endl;
            std::vector<int> results;
            auto start = std::chrono::steady_clock::now();
            int sum = sum_two_vectors_on_threads(num_threads[j], a, b, results, a.size());
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            std::cout << "Sum of two vectors: " << sum << ", elapsed seconds: " << elapsed_seconds.count() << std::endl;
        }
    }
}