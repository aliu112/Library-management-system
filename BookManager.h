#pragma once
#include "Category.h"

class BookManager {
private:
	vector<Category*> categories;

public:
	// Constructors
	BookManager();
	~BookManager();

	// Print functions
	void print();
	void printCategories();
	void printHierarchy();

	// Adders and removers
	void add(Category* category);
	void remove(Category* category);
	bool remove(string title);

	// Category-related functions
	int categoryCount();
	void editCategory(string current, string change);
	void changeBookCategory(string book, string currentCategory, string changeCategory);
	Book* findBook(string book);
	Book* findBook(uint64_t isbn13);
	void exportData();
};