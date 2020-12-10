#include "gtest/gtest.h"
#include "BookManager.h"
#include <fstream>

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

TEST(BookManagerTest, ISBN13InvalidCheck) {
	BookManager bookManager = BookManager();
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "04-16-1989", 270, 44519510892);
	
	EXPECT_EQ(0, book1->getISBN13());
}

TEST(BookManagerTest, ISBN13ValidCheck) {
	BookManager bookManager = BookManager();
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "04-16-1989", 270, 4451952310892);
	
	EXPECT_EQ(4451952310892, book1->getISBN13());
}

TEST(BookManagerTest, DateInvalidCheck) {
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "2-29-1989", 270, 4451952310892);
	
	EXPECT_EQ("00-00-0000", book1->getDate());
}

TEST(BookManagerTest, DateValidCheck) {
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "2-29-2000", 270, 4451952310892);
	
	EXPECT_EQ("2-29-2000", book1->getDate());
}

TEST(BookManagerTest, ExportData) {
	BookManager bookManager = BookManager();
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "04-16-1989", 270, 4451952310892);
	Book* book2 = new Book("How to Program in C++", "John Doe", "04-16-1989", 270, 1732630091782);
	
	Category* category1 = new Category("Test");
	category1->add(book1);
	
	Category* category2 = new Category("My Library");
	category2->add(book2);

	bookManager.add(category1);
	bookManager.add(category2);
	
	bookManager.exportData("out.txt");
	
	std::ifstream infile("out.txt");
	string str;
	std::getline(infile, str);
	infile.close();
	
	EXPECT_EQ("@Test$1", str);
}

TEST(BookManagerTest, ImportData) {
	BookManager bookManager = BookManager();
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "04-16-1989", 270, 4451952310892);
	Book* book2 = new Book("How to Program in C++", "John Doe", "04-16-1989", 270, 1732630091782);
	
	Category* category1 = new Category("Test");
	category1->add(book1);
	
	Category* category2 = new Category("My Library");
	category2->add(book2);

	bookManager.add(category1);
	bookManager.add(category2);
	
	bookManager.exportData("out.txt");
	
	BookManager copiedManager = BookManager();
	copiedManager.importData("out.txt");
	
	Book* testBook = copiedManager.findBook(4451952310892);
	
	EXPECT_EQ("Jacob's Big Adventure", testBook->getTitle());
}

TEST(BookManagerTest, ValidData) {
	BookManager bookManager = BookManager();
	Book* book1 = new Book("Jacob's Big Adventure", "John Doe", "04-16-1989", 270, 4451952310892);
	Book* book2 = new Book("How to Program in C++", "John Doe", "04-16-1989", 270, 1732630091782);
	
	Category* category1 = new Category("Test");
	category1->add(book1);
	
	Category* category2 = new Category("My Library");
	category2->add(book2);

	bookManager.add(category1);
	bookManager.add(category2);
	
	bookManager.exportData("out.txt");
	
	std::ifstream infile("out.txt");
	string str;
	std::getline(infile, str);
	std::getline(infile, str);
	std::getline(infile, str);
	std::getline(infile, str);
	EXPECT_EQ("How to Program in C++$John Doe$04-16-1989$270$1732630091782$1", str);
}