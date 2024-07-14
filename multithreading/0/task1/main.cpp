#include <iostream>
#include <thread>

void process_client_request(int &initial_value, int max_value) {
    int client_id = initial_value;
    while (client_id < max_value) {
        ++initial_value;
        std::cout << "Client with id " << client_id << " added to the queue" << std::endl;
        ++client_id;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void perform_operation(int &initial_value) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int client_id = 0;
    while (initial_value > 0) {
        --initial_value;
        std::cout << "The operator has completed work with " << client_id << " client. Remaining number of clients: "
                  << initial_value << std::endl;
        ++client_id;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main() {
    int clients_in_the_queue, total_clients;
    std::cout << "Enter the current number of clients in the queue: ";
    std::cin >> clients_in_the_queue;
    std::cout << "Enter the total number of clients: ";
    std::cin >> total_clients;
    if (total_clients < clients_in_the_queue) {
        std::cout << "The total number of clients must not be less than the current number of clients in the queue!"
                  << std::endl;
    } else {
        std::thread t1(process_client_request, std::ref(clients_in_the_queue), total_clients);
        std::thread t2(perform_operation, std::ref(clients_in_the_queue));
        t1.join();
        t2.join();
    }
    return 0;
}
