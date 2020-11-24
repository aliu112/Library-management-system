#pragma once
#include <string>

using std::string;

class Media {
protected:
	string title;

public:
	// Constructors
	Media();
	Media(string title);

	// Virtual function for later
	virtual void print();

	// Setter and getter
	void setTitle(string title);
	string getTitle();
};