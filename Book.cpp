#include "Book.h"
#include <iostream>

Book::Book() : Media() {
	this->author = "None";
	this->datePublished = "00-00-0000";
	this->isbn13 = 0;
	this->availability = false;
}

Book::Book(string title, string datePublished, int numPages, int isbn13) : Media(title) {
	this->datePublished = datePublished;
	this->numPages = numPages;
	this->isbn13 = isbn13;
}

Book::Book(string title) : Media(title) {
	this->author = "None";
	this->datePublished = "00-00-0000";
	this->isbn13 = 0;
	this->availability = false;
}

void Book::print() {
	std::cout << "Title: " << this->title << std::endl;
	std::cout << "\tAuthor: " << this->author << std::endl;
	std::cout << "\tDate Published: " << this->datePublished << std::endl;
	std::cout << "\tISBN-13: " << this->isbn13 << std::endl;
	std::cout << "\tAvailable: " << this->availability << std::endl;
}

// Ensure that the given book is the exact one we are looking for
bool Book::operator == (const Book &b) {
	if (this->title == b.title &&
		this->author == b.author &&
		this->isbn13 == b.isbn13 &&
		this->datePublished == b.datePublished)
		return true;

	else
		return false;
}