#include <thread>
#include <iostream>
#include <chrono>
#include <vector>
#include <mutex>

std::mutex output_mutex;

void set_cursor_position(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

void print_progress_bar(int length, int padding) {
    auto thread_id = std::this_thread::get_id();
    auto start = std::chrono::steady_clock::now();

    set_cursor_position(0, padding);
    {
        std::lock_guard<std::mutex> lock(output_mutex);
        std::cout << "Thread ID: " << thread_id << " Progress: ";
    }

    std::string progress(length, ' ');

    for (int i = 0; i < length; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        progress[i] = 'o';
        {
            std::lock_guard<std::mutex> lock(output_mutex);
            set_cursor_position(0, padding);
            std::cout << "Thread ID: " << thread_id << " Progress: " << progress << "  Time: " << (i + 1) << " seconds"
                      << std::flush;
        }
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    {
        std::lock_guard<std::mutex> lock(output_mutex);
        set_cursor_position(0, padding);
        std::cout << "Thread ID: " << thread_id << " Progress: " << progress << "  Time: " << elapsed_seconds.count()
                  << " seconds" << std::endl;
    }
}

int main() {
    int num_threads, length;
    std::cout << "Enter the number of threads: ";
    std::cin >> num_threads;
    std::cout << "Enter the length of the progress bar: ";
    std::cin >> length;

    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(print_progress_bar, length, i + 1);
    }

    for (auto &t: threads) {
        t.join();
    }

    return 0;
}
