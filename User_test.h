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

TEST(UserTest, removeUser2){
    User temp;
    temp.addAccount("hello2","world2");
    temp.addAccount("hello3","world3");
    temp.addAccount("hello4","world4");
    temp.removeAccount("hello2", "world2");
    temp.removeAccount("hello3","world3");
    temp.removeAccount("hello4", "world4");
    EXPECT_EQ(temp.isValidLogin("hello2","world2"), false);
    EXPECT_EQ(temp.isValidLogin("hello3","world3"), false);
    EXPECT_EQ(temp.isValidLogin("hello4","world4"), false);
}

TEST(UserTest, TestExistingUser){
    User temp;
    EXPECT_EQ(temp.isValidLogin("aliu112", "password"), true);
    EXPECT_EQ(temp.isValidLogin("hello", "world"), true);
}

TEST(UserTest, TestNonExistentUser){
    User temp;
    EXPECT_EQ(temp.isValidLogin("aliu11", "passwor"), false);
    EXPECT_EQ(temp.isValidLogin("helo", "worl"), false);
}