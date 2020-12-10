#pragma once
#include "Book.h"
#include <vector>

using std::vector;

class Category : public Media {
private:
	vector<Book*> list;

public:
	// Constructors
	Category();
	Category(string title);
	~Category();

	// Populate virtual function
	void print();

	// Functions for vector manipulation
	void printBooks();

	int bookCount();
	vector<Book*> getBooks();

	Book* findBook(string title);
	Book* findBook(uint64_t isbn13);
	void add(Book*);
	void remove(Book*);
	void remove(string title);
	void remove(uint64_t isbn13);
	void removeAt(int index);
};