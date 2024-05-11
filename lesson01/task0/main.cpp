#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include "list.h"

TEST_CASE("Test Empty", "[list]") {
    List test;
    SECTION("empty list") {
        CHECK(test.Empty());
    }SECTION("non-empty list") {
        test.PushBack(42);
        CHECK(!test.Empty());
    }
}

TEST_CASE("Test Size", "[list]") {
    List test;
    REQUIRE(test.Size() == 0);
    test.PushBack(1);
    REQUIRE(test.Size() == 1);
    test.PushFront(2);
    REQUIRE(test.Size() == 2);
    test.PopBack();
    REQUIRE(test.Size() == 1);
    test.PopFront();
    REQUIRE(test.Size() == 0);
}

TEST_CASE("Test Clear", "[list]") {
    List test;
    test.PushBack(42);
    test.PushBack(44);
    test.Clear();
    REQUIRE(test.Size() == 0);
}

int main() {
    return Catch::Session().run();
}