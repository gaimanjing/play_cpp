#include "nlohmann/json.hpp"

#include <gtest/gtest.h>

using nlohmann::json;

TEST(JsonTest, Initializer_lists_construct) {
  json j{true, 2};
  EXPECT_TRUE(j.is_array());
}

TEST(JsonTest, construct) {
  json j(true);
  EXPECT_TRUE(j.is_boolean());
}

// https://json.nlohmann.me/features/parsing/parse_exceptions/
TEST(JsonTest, parse_exception) {
  auto my_input = "{";
  try {
    auto j = json::parse(my_input);
  } catch (json::parse_error &ex) {
    std::cerr << "parse error at byte " << ex.byte << std::endl;
    GTEST_SUCCEED();
  }
}

TEST(JsonTest, parse_no_exception) {
  auto my_input = "{";
  json j = json::parse(my_input, nullptr, false);
  if (j.is_discarded()) {
    std::cerr << "parse error" << std::endl;
  }

  GTEST_SUCCEED();
}