#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>

class LogMessage {
public:
    enum class Type {
        WarningMessage,
        ErrorMessage,
        FatalErrorMessage,
        UnknownMessage
    };

    LogMessage(Type type, std::string message)
            : type_(type), message_(std::move(message)) {}

    virtual Type type() const {
        return type_;
    }

    virtual const std::string &message() const {
        return message_;
    };

    virtual ~LogMessage() = default;

private:
    Type type_;
    std::string message_;
};

class WarningMessage final : public LogMessage {
public:
    explicit WarningMessage(const std::string &message)
            : LogMessage(Type::WarningMessage, message) {}
};

class ErrorMessage final : public LogMessage {
public:
    explicit ErrorMessage(const std::string &message)
            : LogMessage(Type::ErrorMessage, message) {}
};

class FatalErrorMessage final : public LogMessage {
public:
    explicit FatalErrorMessage(const std::string &message)
            : LogMessage(Type::FatalErrorMessage, message) {}
};

class UnknownMessage final : public LogMessage {
public:
    explicit UnknownMessage(const std::string &message)
            : LogMessage(Type::UnknownMessage, message) {}
};

class MessagesHandler {
public:
    explicit MessagesHandler(std::unique_ptr<MessagesHandler> next_handler)
            : next_handler_(std::move(next_handler)) {}

    void receive_message(const LogMessage &msg) {
        if (handle_message(msg)) {
            return;
        }
        if (next_handler_) {
            next_handler_->receive_message(msg);
        }
    }

    virtual ~MessagesHandler() = default;

private:
    virtual bool handle_message(const LogMessage &msg) = 0;

    std::unique_ptr<MessagesHandler> next_handler_;
};

class WarningHandler final : public MessagesHandler {
public:
    explicit WarningHandler(std::unique_ptr<MessagesHandler> next)
            : MessagesHandler(std::move(next)) {}

private:
    bool handle_message(const LogMessage &msg) override {
        if (msg.type() != LogMessage::Type::WarningMessage) {
            return false;
        }
        std::cerr << msg.message() << '\n';
        return true;
    }
};

class ErrorHandler final : public MessagesHandler {
public:
    ErrorHandler(std::ofstream &error_file, std::unique_ptr<MessagesHandler> next)
            : MessagesHandler(std::move(next)), error_file_(error_file) {}

private:
    bool handle_message(const LogMessage &msg) override {
        if (msg.type() != LogMessage::Type::ErrorMessage) {
            return false;
        }
        error_file_ << msg.message() << '\n';
        return true;
    }

    std::ofstream &error_file_;
};

class FatalErrorHandler final : public MessagesHandler {
public:
    explicit FatalErrorHandler(std::unique_ptr<MessagesHandler> next)
            : MessagesHandler(std::move(next)) {}

private:
    bool handle_message(const LogMessage &msg) override {
        if (msg.type() != LogMessage::Type::FatalErrorMessage) {
            return false;
        }
        throw std::runtime_error(msg.message());
    }
};

class UnknownHandler final : public MessagesHandler {
public:
    explicit UnknownHandler(std::unique_ptr<MessagesHandler> next)
            : MessagesHandler(std::move(next)) {}

private:
    bool handle_message(const LogMessage &msg) override {
        if (msg.type() != LogMessage::Type::UnknownMessage) {
            return false;
        }
        throw std::runtime_error(msg.message());
    }
};

int main() {
    auto unknown_handler = std::make_unique<UnknownHandler>(nullptr);
    auto warning_handler = std::make_unique<WarningHandler>(std::move(unknown_handler));
    std::ofstream error_log("error.log");
    auto error_handler = std::make_unique<ErrorHandler>(error_log, std::move(warning_handler));
    auto fatal_error_handler = std::make_unique<FatalErrorHandler>(std::move(error_handler));

    try {
        fatal_error_handler->receive_message(WarningMessage("Warning"));
        fatal_error_handler->receive_message(ErrorMessage("Error"));
        fatal_error_handler->receive_message(FatalErrorMessage("Fatal error"));
        fatal_error_handler->receive_message(UnknownMessage("Unknown"));
    }
    catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
}