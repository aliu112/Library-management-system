#include "gtest/gtest.h"
#include "BookManager.h"

TEST(BookManagerTest, AddCategory) {
	BookManager bookManager = BookManager();
	Category* category1 = new Category("Test");
	Category* category2 = new Category("My Library");
	
	bookManager.add(category1);
	bookManager.add(category2);
	
	EXPECT_EQ(2, bookManager.categoryCount());
}

TEST(BookManagerTest, RemoveCategoryUsingCategory) {
	BookManager bookManager = BookManager();
	Category* category1 = new Category("Test");
	Category* category2 = new Category("My Library");
	
	bookManager.add(category1);
	bookManager.add(category2);
	
	bookManager.remove(category1);
	
	EXPECT_EQ(1, bookManager.categoryCount());
}

TEST(BookManagerTest, RemoveCategoryUsingTitle) {
	BookManager bookManager = BookManager();
	Category* category1 = new Category("Test");
	Category* category2 = new Category("My Library");
	
	bookManager.add(category1);
	bookManager.add(category2);
	
	bookManager.remove("My Library");
	
	EXPECT_EQ(1, bookManager.categoryCount());
}

TEST(BookManagerTest, FindBookUsingTitle) {
	BookManager bookManager = BookManager();
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "04-16-1989", 270, 4451952310892);
	Book* book2 = new Book("How to Program in C++", "John Doe", "04-16-1989", 270, 1732630091782);
	
	Category* category1 = new Category("Test");
	category1->add(book1);
	
	Category* category2 = new Category("My Library");
	category2->add(book2);

	bookManager.add(category1);
	bookManager.add(category2);
	
	Book* test = bookManager.findBook("How to Program in C++");
	
	EXPECT_EQ(1732630091782, test->getISBN13());
}

TEST(BookManagerTest, FindBookUsingISBN13) {
	BookManager bookManager = BookManager();
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "04-16-1989", 270, 4451952310892);
	Book* book2 = new Book("How to Program in C++", "John Doe", "04-16-1989", 270, 1732630091782);
	
	Category* category1 = new Category("Test");
	category1->add(book1);
	
	Category* category2 = new Category("My Library");
	category2->add(book2);

	bookManager.add(category1);
	bookManager.add(category2);
	
	Book* test = bookManager.findBook(4451952310892);
	
	EXPECT_EQ("Jacob's Big Adventure", test->getTitle());
}