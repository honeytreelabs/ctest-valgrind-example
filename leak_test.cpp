#include <catch2/catch_test_macros.hpp>

#include <cstdio>

int function_under_test() {
  new char[20]; // deliberate memory leak
  return printf("Hello, World!\n");
}

TEST_CASE("states of inputs unchanged", "[single-file]") {
  REQUIRE(function_under_test() == 14);
}
