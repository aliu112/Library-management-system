#include "gtest/gtest.h"
#include "Media_test.h"
#include "Book_test.h"
#include "Category_test.h"
#include "BookManager_test.h"
#include "owedDebts_test.h"
#include "User_test.h"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}