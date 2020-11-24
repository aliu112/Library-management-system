#pragma once
#include "Media.h"
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

	// Populate virtual function
	void print();

	void setTitle(string title);
	string getTitle();
};