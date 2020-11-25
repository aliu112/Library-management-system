#pragma once
#include "Media.h"

class Book : public Media {
private:
	string author;
	string datePublished;
	int numPages;
	long int isbn13;
	bool availability;

public:
	// Constructors
	Book();
	Book(string title);
	Book(string title, string author, string datePublished, int numPages, long int isbn13);

	// Populate virtual function
	void print();

	// Setters and getters
	void setAuthor(string author);
	string getAuthor();

	void setDate(string date);
	string getDate();

	void setPages(int pages);
	int getPages();

	void setISBN13(long int isbn13);
	long int getISBN13();

	void setAvailable(bool val);
	bool getAvailable();

	// Extra functions
	bool operator == (const Book &b);
};
