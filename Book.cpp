#include "Book.h"
#include <iostream>

Book::Book() : Media() {
	this->setAuthor("None");
	this->setDate("00-00-0000");
	this->setISBN13(-1);
	this->setAvailable(false);
}

Book::Book(string title, string author, string datePublished, int numPages, long int isbn13) : Media(title) {
	this->setAuthor(author);
	this->setDate(datePublished);
	this->setISBN13(numPages);
	this->setAvailable(isbn13);
}

Book::Book(string title) : Media(title) {
	this->setAuthor("None");
	this->setDate("00-00-0000");
	this->setISBN13(-1);
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

void Book::setISBN13(long int isbn13) {
	this->isbn13 = isbn13;
}

long int Book::getISBN13() {
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