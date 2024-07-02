#include <iostream>
#include <pqxx/pqxx>
#include <vector>

namespace database {
    struct ClientInfo {
        int id;
        std::string first_name;
        std::string last_name;
        std::string email;
        std::vector<std::string> phones;
    };

    void print_client_info(const ClientInfo &c) {
        if (c.first_name.empty() || c.last_name.empty() || c.email.empty()) {
            std::cout << "Client not exists!" << std::endl;
        } else {
            std::cout << "ID: " << c.id << ", first name: " << c.first_name << ", last name: " << c.last_name
                      << ", e-mail: " << c.email;
            if (!c.phones.empty()) {
                std::cout << ", phones: ";
                bool is_first = true;
                for (const auto &phone: c.phones) {
                    if (is_first) {
                        std::cout << phone;
                        is_first = false;
                    } else {
                        std::cout << ", " << phone;
                    }
                }
            }
            std::cout << std::endl;
        }
    }

    class ClientManager {
    public:
        ClientManager()
        try: c_(pqxx::connection(
                "host=localhost "
                "port=5432 "
                "dbname=clients "
                "user=postgres "
                "password=postgres ")) {
            create_tables();
        }
        catch (pqxx::sql_error &e) {
            std::cout << e.what() << std::endl;
        }

        int add_client(const std::string &first_name, const std::string &last_name, const std::string &email,
                       const std::vector<std::string> &numbers = {}) {
            pqxx::work tx{c_};
            pqxx::result r = tx.exec_params("INSERT INTO client(first_name, last_name, email) "
                                            "VALUES ($1, $2, $3) RETURNING id", first_name, last_name, email);
            tx.commit();
            if (!numbers.empty()) {
                int client_id = r[0][0].as<int>();
                for (const auto &number: numbers) {
                    add_number(client_id, number);
                }
            }
            return r[0][0].as<int>();
        }

        void add_number(int client_id, const std::string &number) {
            pqxx::work tx{c_};
            tx.exec_params("INSERT INTO phone(client_id, number) VALUES ($1, $2)", client_id, number);
            tx.commit();
        }

        void change_client_email(int client_id, std::string new_email) {
            pqxx::work tx{c_};
            tx.exec_params("UPDATE client SET email = $1 WHERE id = $2", new_email, client_id);
            tx.commit();
        }

        void delete_number(const std::string &number) {
            pqxx::work tx{c_};
            tx.exec_params("DELETE FROM phone WHERE number = $1", number);
            tx.commit();
        }

        void delete_client_by_id(int client_id) {
            pqxx::work tx{c_};
            tx.exec_params("DELETE FROM phone WHERE client_id = $1", client_id);
            tx.exec_params("DELETE FROM client WHERE id = $1", client_id);
            tx.commit();
        }

        void delete_clients_by_fullname(const std::string &search_first_name, const std::string &search_last_name) {
            pqxx::work tx{c_};
            std::vector<int> deleting_ids;
            for (const auto [id]: tx.query<int>("SELECT id FROM client WHERE first_name = " +
                                                tx.quote(search_first_name) + "AND last_name = " +
                                                tx.quote(search_last_name))) {
                deleting_ids.push_back(id);
            }
            tx.commit();
            for (const auto id: deleting_ids) {
                delete_client_by_id(id);
            }
        }

        ClientInfo find_client_by_email(const std::string &search_email) {
            ClientInfo c;
            pqxx::work tx{c_};
            std::vector<std::string> phones;

            for (const auto &[id, first_name, last_name, email]: tx.query<int, std::string, std::string, std::string>(
                    "SELECT id, first_name, last_name, email from client WHERE email = " +
                    tx.quote(search_email))) {
                c.id = id;
                c.first_name = first_name;
                c.last_name = last_name;
                c.email = email;
                for (const auto &[phone]: tx.query<std::string>(
                        "SELECT number FROM phone WHERE client_id = " + tx.quote(c.id))) {
                    phones.push_back(phone);
                }
                c.phones = phones;
            }
            return c;
        }

        ClientInfo find_client_by_phone(const std::string &search_number) {
            ClientInfo c;
            pqxx::work tx{c_};

            for (const auto &[email]: tx.query<std::string>(
                    "SELECT email FROM client WHERE id IN (SELECT client_id from phone WHERE number = " +
                    tx.quote(search_number) + ")")) {
                tx.commit();
                return find_client_by_email(email);
            }
            return c;
        }

    private:
        pqxx::connection c_;

        void create_tables() {
            pqxx::work tx{c_};
            tx.exec("CREATE TABLE IF NOT EXISTS client ( "
                    "id SERIAL PRIMARY KEY, "
                    "first_name VARCHAR(42) NOT NULL, "
                    "last_name VARCHAR(42) NOT NULL, "
                    "email VARCHAR(42) UNIQUE NOT NULL);");
            tx.exec("CREATE TABLE IF NOT EXISTS phone ( "
                    "id SERIAL PRIMARY KEY, "
                    "client_id INTEGER NOT NULL REFERENCES client(id), "
                    "number VARCHAR(12) UNIQUE NOT NULL);");
            tx.commit();
        }
    };
}

int main() {
    database::ClientManager m;
    m.add_client("Petr", "Petrov", "petrov@bb.rr");
    m.add_client("Mikhail", "Mikhailov", "mikhailov@bb.rr", {"+79111111111", "+79222222222"});
    m.add_client("Ivan", "Ivanov", "ivanov@bb.rr", {"+79333333333"});
    m.add_client("Petr", "Petrov", "ppetrov@bb.rr", {"+79444444444"});
    print_client_info(m.find_client_by_email("mikhailov@bb.rr"));
    m.add_number(m.find_client_by_email("mikhailov@bb.rr").id, "+79555555555");
    print_client_info(m.find_client_by_email("mikhailov@bb.rr"));
    print_client_info(m.find_client_by_email("ivanov@bb.rr"));
    m.delete_number("+79333333333");
    print_client_info(m.find_client_by_email("ivanov@bb.rr"));
    m.change_client_email(m.find_client_by_email("ivanov@bb.rr").id, "iivanov@bb.rr");
    print_client_info(m.find_client_by_email("iivanov@bb.rr"));
    print_client_info(m.find_client_by_email("ivanov@bb.rr"));
    print_client_info(m.find_client_by_phone("+79111111111"));
    print_client_info(m.find_client_by_phone("+79666666666"));
    m.delete_client_by_id(m.find_client_by_email("iivanov@bb.rr").id);
    print_client_info(m.find_client_by_email("iivanov@bb.rr"));
    m.delete_clients_by_fullname("Petr", "Petrov");
    print_client_info(m.find_client_by_email("petrov@bb.rr"));
    print_client_info(m.find_client_by_phone("+79444444444"));
}
