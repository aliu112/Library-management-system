#pragma once
#include "Media.h"

class Book : public Media {
private:
	string author;
	string datePublished;
	int numPages;
	int isbn13;
	bool availability;

public:
	// Constructors
	Book();
	Book(string title);
	Book(string title, string datePublished, int numPages, int isbn13);

	// Populate virtual function
	void print();

	// Extra functions
	bool operator == (const Book &b);
};
