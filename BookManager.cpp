#include "BookManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

BookManager::BookManager() {
}

BookManager::~BookManager() {
	for (int i = 0; i < this->categories.size(); i++)
		delete this->categories[i];
}

void BookManager::print() {
	std::cout << "Book Manager" << std::endl;
}

void BookManager::printCategories() {
	for (int i = 0; i < this->categories.size(); i++)
		this->categories[i]->print();
}

void BookManager::printHierarchy() {
	this->print();
	for (int i = 0; i < this->categories.size(); i++) {
		this->categories[i]->print();
		this->categories[i]->printBooks();
	}
}

void BookManager::add(Category* category) {
	this->categories.push_back(category);
}

void BookManager::remove(Category* category) {
	this->remove(category->getTitle());
}

bool BookManager::remove(string title) {
	for (int i = 0; i < this->categories.size(); i++)
		if (title == this->categories[i]->getTitle())
		{
			this->categories.erase(this->categories.begin() + i);
			return 1;
		}
		return 0;
}

int BookManager::findCategory(string name)
{
	int temp = categories.size();
    for(int i=0; i < temp; ++i)
    {
        if(name == categories.at(i)->getTitle())
        {
            return i;
        }
    }
    return -1;
}
void BookManager::addBook(Book* temp, int numCategory)
{
	categories.at(numCategory)->add(temp);
}
void BookManager::removeBook(string temp , int numCategory)
{
	categories.at(numCategory)->remove(temp);
}
int BookManager::categoryCount() {
	return this->categories.size();
}

void BookManager::editCategory(string current, string change) {
	for (int i = 0; i < this->categories.size(); i++)
		if (current == this->categories[i]->getTitle())
			this->categories[i]->setTitle(change);
}

void BookManager::changeBookCategory(string book, string currentCategory, string changeCategory) {
	for (int i = 0; i < this->categories.size(); i++)
	{
		if (this->categories[i]->getTitle() == currentCategory)
		{
			// Get the book
			Book* temp = this->categories[i]->findBook(book);
			if (temp->getTitle() != "BookNotFound")
			{
				// Remove the book from the old list
				Book* found = new Book(temp);
				this->categories[i]->remove(temp);
				
				// Add it to the new list
				for (int i = 0; i < this->categories.size(); i++)
					if (this->categories[i]->getTitle() == changeCategory)
					{
						this->categories[i]->add(found);
						break;
					}

				break;
			}
		}
	}
}

Book* BookManager::findBook(string title) {
	Book* temp = new Book();
	for (int i = 0; i < this->categories.size(); i++)
	{
		delete temp;
		temp = this->categories[i]->findBook(title);
		if (temp->getTitle() != "BookNotFound")
			return temp;
	}
	// Returns "None" if nothing is found
	return temp;
}

Book* BookManager::findBook(uint64_t isbn13) {
	Book* temp = new Book();
	for (int i = 0; i < this->categories.size(); i++)
	{
		delete temp;
		temp = this->categories[i]->findBook(isbn13);
		if (temp->getTitle() != "BookNotFound")
			return temp;
	}
	// Returns "None" if nothing is found
	return temp;
}

void BookManager::exportData(string file) {
	const char header = '@';
	const char endPoint = '$';
	const char endFile = '%';

	std::ofstream outfile(file);
	if (!outfile)
		std::cout << "Error: Unable to create output file" << std::endl;
	else
	{
		for (int i = 0; i < this->categories.size(); i++) 
		{
			vector<Book*> currentBooks = this->categories[i]->getBooks();

			// Category title, number of books
			outfile << header << this->categories[i]->getTitle() << endPoint << this->categories[i]->bookCount() << std::endl;
			
			// All the info for one book per line
			for (auto book : currentBooks)
			{
				outfile << book->getTitle() << endPoint;
				outfile << book->getAuthor() << endPoint;
				outfile << book->getDate() << endPoint;
				outfile << book->getPages() << endPoint;
				outfile << book->getISBN13() << endPoint;
				outfile << book->isAvailable() << std::endl;
			}
		}

		// Not the same as "
		outfile << endFile;
		outfile.close();
	}
}

// Weird characters were used to ensure that no valid characters mess up the file hierarchy
// Including characters for other languages
void BookManager::importData(string file) {
	const char header = '@';
	const char endPoint = '$';
	const char endFile = '%';

	std::ifstream infile(file);
	if (!infile)
		std::cout << "Error: Unable to read the given file" << std::endl;
	else
	{
		bool loop = true;
		while (loop)
		{
			string input;
			string categoryTitle = "";
			int bookCount = 0;
			std::getline(infile, input);

			if (input[0] == endFile)
			{
				loop = false;
				break;
			}

			// Get category header (category title, then number of books)
			if (input[0] == header)
			{
				// Get rid of the header char
				input.erase(0, 1);

				// Setup for string splitting
				std::stringstream strstream(input);
				string hTemp;
				vector<string> split;
				while (std::getline(strstream, hTemp, endPoint))
				{
					split.push_back(hTemp);
				}

				// Get the category title
				categoryTitle = split[0];

				// Get how many books to find
				bookCount = std::stoi(split[1]);
			}

			Category* category = new Category(categoryTitle);

			// Iterate through the file to get the needed number of books
			for (int i = 0; i < bookCount; i++)
			{
				// Setup stringstream
				string strTemp;
				std::getline(infile, strTemp);
				std::stringstream strstream(strTemp);

				// Split the given string based on the delimiter
				string bTemp;
				vector<string> split;
				while (std::getline(strstream, bTemp, endPoint))
				{
					split.push_back(bTemp);
				}

				// Cast for ISBN-13 value
				uint64_t isbn13;
				std::istringstream iss(split[4]);
				iss >> isbn13;
				
				// Assume false until proven otherwise
				bool availability = false;
				if (split[5] == "1")
					availability = true;

				Book* tempBook = new Book(split[0], split[1], split[2], std::stoi(split[3]), isbn13, availability);
				category->add(tempBook);
			}

			this->add(category);
		}
	}
}