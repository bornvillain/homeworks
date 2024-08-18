#include <iostream>
#include <string>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;

    virtual void print(const std::string &message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
    void print(const std::string &message) override {
        std::cout << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
public:
    explicit FileLogCommand(std::ofstream &file)
            : file_(std::move(file)) {}

    void print(const std::string &message) override {
        file_ << message;
    }

private:
    std::ofstream file_;
};

int main() {
    ConsoleLogCommand console_log;
    console_log.print("some message to console");

    std::ofstream f_out("test.txt");
    FileLogCommand file_log(f_out);
    file_log.print("some message to file");
    f_out.close();
}