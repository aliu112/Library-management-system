#include "gtest/gtest.h"
#include "Media.h"

TEST(MediaTest, DefaultConstructor) {
	Media* empty = new Media();
	EXPECT_EQ("None", empty->getTitle());
}

TEST(MediaTest, OverloadedConstructor) {
	Media* test = new Media("Hello World");
	EXPECT_EQ("Hello World", test->getTitle());
}