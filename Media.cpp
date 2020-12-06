#include "Media.h"

Media::Media() {
	this->title = "None";
}

Media::Media(string title) {
	this->setTitle(title);
}

void Media::print() {}

void Media::setTitle(string title) {
	this->title = title;
}

string Media::getTitle() {
	return this->title;
}