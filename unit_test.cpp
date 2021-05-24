#include "gtest/gtest.h"
#include "rand.hpp"
#include "add.hpp"
#include "op.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "mult.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
