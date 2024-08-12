#include <cassert>
#include "sql_query_builder.h"
#include <iostream>

int main() {
    AdvancedSqlSelectQueryBuilder query_builder;
    query_builder.AddColumns({"name", "phone"});
    query_builder.AddFrom("students");
    query_builder.AddCondition("id", '>', "42");

    std::cout << query_builder.BuildQuery();
    assert(query_builder.BuildQuery() ==
           "SELECT name, phone FROM students WHERE id>42;");
}