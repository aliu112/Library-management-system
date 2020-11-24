#include "gtest/gtest.h"
#include "User_test.h"
#include "owedDebts_test.h"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}