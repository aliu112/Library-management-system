#pragma once
#include "Media.h"

class Book : public Media {
private:
	string author;
	string datePublished;
	int numPages;
	uint64_t isbn13;
	bool availability;

public:
	// Constructors
	Book();
	Book(string title);
	Book(string title, string author, string datePublished, int numPages, uint64_t isbn13);

	// Populate virtual function
	void print();

	// Setters and getters
	void setAuthor(string author);
	string getAuthor();

	void setDate(string date);
	string getDate();

	void setPages(int pages);
	int getPages();

	void setISBN13(uint64_t isbn13);
	uint64_t getISBN13();

	void setAvailable(bool val);
	bool isAvailable();

	// Extra functions
	bool compare(Book *b);
};
