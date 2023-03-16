#include "nlohmann/json.hpp"

#include <gtest/gtest.h>

using nlohmann::json;

TEST(JsonTest, Initializer_lists_construct) {
  json j{true};
  EXPECT_TRUE(j.is_array());
}