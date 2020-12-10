#include "Book.h"
#include <iostream>
#include <sstream>
#include <vector>

using std::vector;

Book::Book() : Media() {
	this->setAuthor("None");
	this->setDate("00-00-0000");
	this->setPages(0);
	this->setISBN13(0);
	this->setAvailable(false);
}

Book::Book(string title, string author, string datePublished, int numPages, uint64_t isbn13) : Media(title) {
	this->setAuthor(author);
	this->setDate(datePublished);
	this->setPages(numPages);
	this->setISBN13(isbn13);
	this->setAvailable(true);
}

Book::Book(string title, string author, string datePublished, int numPages, uint64_t isbn13, bool availability) : Media(title) {
	this->setAuthor(author);
	this->setDate(datePublished);
	this->setPages(numPages);
	this->setISBN13(isbn13);
	this->setAvailable(availability);
}

Book::Book(Book* book) : Book(book->getTitle(), book->getAuthor(), book->getDate(), book->getPages(), book->isbn13, book->isAvailable()) {
}

Book::Book(string title) : Media(title) {
	this->setAuthor("None");
	this->setDate("00-00-0000");
	this->setISBN13(0);
	this->setAvailable(false);
}

void Book::print() {
	std::cout << "Title: " << this->title << std::endl;
	std::cout << "\tAuthor: " << this->author << std::endl;
	std::cout << "\tDate Published: " << this->datePublished << std::endl;
	std::cout << "\tISBN-13: " << this->isbn13 << std::endl;
	std::cout << "\tAvailable: " << this->availability << std::endl;
}

void Book::setAuthor(string author) {
	this->author = author;
}

string Book::getAuthor() {
	return this->author;
}

void Book::setDate(string date) {
	std::stringstream ss(date);

	vector<int> dateCodes;
	string temp;
	while (std::getline(ss, temp, '-'))
	{
		dateCodes.push_back(std::stoi(temp));
	}

	bool error = false;

	// [0] = month, [1] = day, [2] = year
	if (dateCodes[0] < 1 || dateCodes[0] > 12)
		error = true;

	if (dateCodes[1] < 1 || dateCodes[1] > 31)
		error = true;

	if (dateCodes[2] < 0 || dateCodes[2] > 9999)
		error = true;

	// February edge case accounting for leap year
	if (dateCodes[0] == 2)
		if (dateCodes[1] == 29)
		{
			if (dateCodes[2] % 4 != 0)
				error = true;
		}
		else if (dateCodes[1] > 29)
			error = true;

	if (error)
		this->datePublished = "00-00-0000";
	else
		this->datePublished = date;
}

string Book::getDate() {
	return this->datePublished;
}

void Book::setPages(int pages) {
	this->numPages = pages;
}

int Book::getPages() {
	return this->numPages;
}

void Book::setISBN13(uint64_t isbn13) {
	// Invalid value right off the bat
	if (isbn13 <= 0)
		this->isbn13 = 0;
	else
	{
		// Ensure that the value is exactly 13 digits
		uint64_t copy = isbn13;
		int digits = 0;
		while (copy)
		{
			copy /= 10;
			digits++;
		}

		if (digits != 13)
			this->isbn13 = 0;
		else
			this->isbn13 = isbn13;
	}
}

uint64_t Book::getISBN13() {
	return this->isbn13;
}

void Book::setAvailable(bool val) {
	this->availability = val;
}

bool Book::isAvailable() {
	return this->availability;
}

// Ensure that the given book is the exact one we are looking for
bool Book::compare(Book *b) {
	return (this->getTitle() == b->getTitle() && 
		this->getAuthor() == b->getAuthor() && 
		this->getISBN13() == b->getISBN13() && 
		this->getDate() == b->getDate());
}