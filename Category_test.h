#include "gtest/gtest.h"
#include "Category.h"

TEST(CategoryTest, DefaultConstructor) {
	Media* empty = new Category();
	EXPECT_EQ("None", empty->getTitle());
}

TEST(CategoryTest, OverloadedConstructor) {
	Media* test = new Category("Hello World");
	EXPECT_EQ("Hello World", test->getTitle());
}

TEST(CategoryTest, FindBook) {
	Book* book1 = new Book("Jacob's Big Adventure");

	Category* category1 = new Category();
	category1->add(book1);
	Media* found = category1->findBook("Jacob's Big Adventure");
	EXPECT_EQ("Jacob's Big Adventure", found->getTitle());
}

TEST(CategoryTest, AddBook) {
	Book* book1 = new Book("Jacob's Big Adventure");

	Category* category1 = new Category();
	category1->add(book1);
	EXPECT_EQ(1, category1->bookCount());
}

TEST(CategoryTest, RemoveUsingBook) {
	Book* book1 = new Book("Jacob's Big Adventure");
	Book* book2 = new Book("How to Program in C++");
	Book* book3 = new Book("Satistics for Dummies");
	Book* book4 = new Book("How to Program in C++");

	Category* category1 = new Category();
	category1->add(book1);
	category1->add(book2);
	category1->add(book3);
	category1->remove(book4);
	EXPECT_EQ(2, category1->bookCount());
}

TEST(CategoryTest, RemoveUsingTitle) {
	Book* book1 = new Book("Jacob's Big Adventure");
	Book* book2 = new Book("How to Program in C++");
	Book* book3 = new Book("Satistics for Dummies");

	Category* category1 = new Category();
	category1->add(book1);
	category1->add(book2);
	category1->add(book3);
	category1->remove("How to Program in C++");
	EXPECT_EQ(2, category1->bookCount());
}

TEST(CategoryTest, RemoveUsingISBN13) {
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "04-16-1989", 270, 4451952310892);
	Book* book2 = new Book("How to Program in C++", "John Doe", "04-16-1989", 270, 1732630091782);
	Book* book3 = new Book("Satistics for Dummies", "John Doe", "04-16-1989", 270, 7388419576579);

	Category* category1 = new Category();
	category1->add(book1);
	category1->add(book2);
	category1->add(book3);
	category1->remove(7388419576579);
	EXPECT_EQ(2, category1->bookCount());
}

TEST(CategoryTest, RemoveUsingIndex) {
	Book* book1 = new Book("Jacob's Big Adventure");
	Book* book2 = new Book("How to Program in C++");
	Book* book3 = new Book("Satistics for Dummies");

	Category* category1 = new Category();
	category1->add(book1);
	category1->add(book2);
	category1->add(book3);
	category1->removeAt(2);
	EXPECT_EQ(2, category1->bookCount());
}