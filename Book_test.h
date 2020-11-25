#include "gtest/gtest.h"
#include "Book.h"

TEST(BookTest, DefaultConstructor) {
	Book* empty = new Book();
	EXPECT_EQ("None", empty->getTitle());
}

TEST(BookTest, OverloadedConstructor) {
	Book* test = new Book("Hello World");
	EXPECT_EQ("Hello World", test->getTitle());
}

TEST(BookTest, ChangeAuthor) {
	Book* test = new Book("Hello World");
	test->setAuthor("Morgan Freeman");
	EXPECT_EQ("Morgan Freeman", test->getAuthor());
}

TEST(BookTest, ChangeDate) {
	Book* test = new Book("Hello World");
	test->setDate("12-24-1999");
	EXPECT_EQ("12-24-1999", test->getDate());
}

TEST(BookTest, ChangePages) {
	Book* test = new Book("Hello World");
	test->setPages(893);
	EXPECT_EQ(893, test->getPages());
}

TEST(BookTest, ChangeISBN13) {
	Book* test = new Book("Hello World");
	test->setISBN13(1234567892345);
	EXPECT_EQ(1234567892345, test->getISBN13());
}

TEST(BookTest, ChangeAvailability) {
	Book* test = new Book("Hello World");
	test->setAvailable(true);
	EXPECT_EQ(true, test->isAvailable());
}

TEST(BookTest, BoolOperator) {
	Book* test = new Book("Hello World", "John Doe", "04-16-1989", 270, 1234567892345);
	Book* test2 = new Book("Hello World", "John Doe", "04-16-1989", 270, 1234567892345);
	
	EXPECT_EQ(true, test->compare(test2));
}