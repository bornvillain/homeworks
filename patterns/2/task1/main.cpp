#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

class Observer {
public:
    virtual ~Observer() = default;

    virtual void onWarning(const std::string &message) {};

    virtual void onError(const std::string &message) {};

    virtual void onFatalError(const std::string &message) {};
};

class WarningObserver : public Observer {
public:
    void onWarning(const std::string &message) override {
        std::cerr << message << std::endl;
    }
};

class ErrorObserver : public Observer {
public:
    explicit ErrorObserver(std::ofstream &error_file)
            : error_file_(std::move(error_file)) {}

    void onError(const std::string &message) override {
        error_file_ << message;
    }

private:
    std::ofstream error_file_;
};

class FatalErrorObserver : public Observer {
public:
    explicit FatalErrorObserver(std::ofstream &fatal_error_file)
            : fatal_error_file_(std::move(fatal_error_file)) {}

    void onFatalError(const std::string &message) override {
        std::cerr << message << std::endl;
        fatal_error_file_ << message;
    }

private:
    std::ofstream fatal_error_file_;
};

class Observed {
public:
    void subscribe(const std::shared_ptr<Observer> &observer) {
        observers_.push_back(observer);
    }

    void warning(const std::string &message) const {
        notify_observers(&Observer::onWarning, message);
    }

    void error(const std::string &message) const {
        notify_observers(&Observer::onError, message);
    }

    void fatalError(const std::string &message) const {
        notify_observers(&Observer::onFatalError, message);
    }

private:

    void notify_observers(void (Observer::*ptr)(const std::string &), const std::string &message) const {
        for (const auto &observer: observers_) {
            if (observer) {
                (observer.get()->*ptr)(message);
            }
        }
    }

    std::vector<std::shared_ptr<Observer>> observers_;
};

int main() {
    auto observer1 = std::make_shared<WarningObserver>();
    std::ofstream error_file("error.log");
    auto observer2 = std::make_shared<ErrorObserver>(error_file);
    std::ofstream fatal_error_file("fatal_error.log");
    auto observer3 = std::make_shared<FatalErrorObserver>(fatal_error_file);

    Observed observed;
    observed.subscribe(observer1);
    observed.subscribe(observer2);
    observed.subscribe(observer3);

    observed.warning("warning");
    observed.error("error");
    observed.fatalError("fatal error");
}