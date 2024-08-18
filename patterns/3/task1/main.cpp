#include <fstream>

class Printable {
public:
    Printable(const std::string &data)
            : data_(data) {}

    virtual ~Printable() = default;

    virtual std::string print() const = 0;

    std::string get_data() const {
        return data_;
    }

private:
    std::string data_;
};

class PrintableText final : public Printable {
public:
    PrintableText(const std::string &data)
            : Printable(data) {}

    std::string print() const override {
        return get_data();
    }
};

class PrintableHTML final : public Printable {
public:
    PrintableHTML(const std::string &data)
            : Printable(data) {}

    std::string print() const override {
        return "<html>" + get_data() + "<html/>";
    }
};

class PrintableJson final : public Printable {
public:
    PrintableJson(const std::string &data)
            : Printable(data) {}

    std::string print() const override {
        return "{ \"data\": \"" + get_data() + "\"}";
    }
};

void save_printable_to_file(const Printable &printable, std::ofstream &file) {
    file << printable.print();
}

void save_printable_to_json(const Printable &printable, std::ofstream &file) {
    file << PrintableJson(printable.get_data()).print();
}

void save_printable_to_html(const Printable &printable, std::ofstream &file) {
    file << PrintableHTML(printable.get_data()).print();
}

void save_printable_to_text(const Printable &printable, std::ofstream &file) {
    file << PrintableText(printable.get_data()).print();
}

int main() {
    std::ofstream f_text("file.txt");
    std::ofstream f_json("file.json");
    std::ofstream f_html("file.html");

    PrintableHTML p_html("example");
    save_printable_to_file(p_html, f_html);
    save_printable_to_text(p_html, f_text);
    save_printable_to_json(p_html, f_json);
}