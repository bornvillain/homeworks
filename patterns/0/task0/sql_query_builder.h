#pragma once

#include <string>
#include <vector>
#include <map>

class SqlSelectQueryBuilder {
public:
    SqlSelectQueryBuilder &AddColumn(const std::string &column) {
        columns_.push_back(column);
        return *this;
    }

    SqlSelectQueryBuilder &AddFrom(const std::string &table) {
        table_ = table;
        return *this;
    }

    SqlSelectQueryBuilder &AddWhere(const std::string &key, const std::string &value) {
        conditions_[key] = value;
        return *this;
    }

    std::string BuildQuery() {
        std::string query = "SELECT ";
        if (columns_.empty()) {
            query += " * ";
        } else {
            bool is_first = true;
            for (const auto &column: columns_) {
                if (is_first) {
                    query += column;
                    is_first = false;
                } else {
                    query += ", " + column;
                }
            }
        }
        query += " FROM " + table_;

        if (!conditions_.empty()) {
            query += " WHERE ";
            bool is_first = true;
            for (const auto &[key, value]: conditions_) {
                if (is_first) {
                    query += key + "=" + value;
                    is_first = false;
                } else {
                    query += " AND " + key + "=" + value;
                }
            }
        }
        query += ";";
        return query;
    }

private:
    std::vector<std::string> columns_;
    std::string table_;
    std::map<std::string, std::string> conditions_;
};
