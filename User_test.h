#include "gtest/gtest.h"
#include "User.h"

TEST(UserTest, addUser){
    User temp;
    temp.addAccount("hello","world");
    EXPECT_EQ(temp.isValidLogin("hello","world"), true);
}
TEST(UserTest, removeUser){
    User temp;
    temp.addAccount("hello2","world2");
    temp.removeAccount("hello2", "world2");
    EXPECT_EQ(temp.isValidLogin("hello2","world2"), false);
}
