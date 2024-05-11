#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include "list.h"

TEST_CASE("Test PushBack", "[list]") {
    List test;
    test.PushBack(42);
    REQUIRE(test.Size() == 1);
    test.PushBack(44);
    REQUIRE(test.Size() == 2);
    REQUIRE(test.PopFront() == 42);
    REQUIRE(test.Size() == 1);
    REQUIRE(test.PopBack() == 44);
    REQUIRE(test.Size() == 0);
    CHECK(test.Empty());
}

TEST_CASE("Test PushFront", "[list]") {
    List test;
    test.PushFront(42);
    REQUIRE(test.Size() == 1);
    test.PushFront(44);
    REQUIRE(test.Size() == 2);
    REQUIRE(test.PopFront() == 44);
    REQUIRE(test.Size() == 1);
    REQUIRE(test.PopBack() == 42);
    REQUIRE(test.Size() == 0);
    CHECK(test.Empty());
}

TEST_CASE("Test PopBack", "[list]") {
    List test;
    REQUIRE_THROWS_AS(test.PopBack(),std::runtime_error);
}

TEST_CASE("Test PopFront", "[list]") {
    List test;
    REQUIRE_THROWS_AS(test.PopBack(),std::runtime_error);
}

int main() {
    return Catch::Session().run();
}