#include "InfCarriers.h"
InfCarriers::InfCarriers() {
	_type = -1;
	_author = Author();
	_title = "Uknown";
	_dateOfIssue = "Uknown";
	_taken = false;
}
InfCarriers::InfCarriers(int type, Author author, string title, string dateOfIssue, bool taken) {
	_type = type;
	_author = author;
	_title = title;
	_dateOfIssue = dateOfIssue;
	_taken = taken;
}
InfCarriers::~InfCarriers() {
	//cout << "Item destroyed";
}

int InfCarriers::GetType() const {
	return _type;
}
void InfCarriers::SetType(int type) {
	_type = type;
}


Author InfCarriers::GetAuthor() const {
	return _author;
}
void InfCarriers::SetAuthor(Author author) {
	_author = author;
}


string InfCarriers::GetTitle() const {
	return _title;
}
void InfCarriers::SetTitle(string title) {
	_title = title;
}


string InfCarriers::GetDateOfIssue() const {
	return _dateOfIssue;
}
void InfCarriers::SetDateOfIssue(string dateOfIssue) {
	_dateOfIssue = dateOfIssue;
}


bool InfCarriers::GetTaken() const {
	return _taken;
}
void InfCarriers::SetTaken(bool taken) {
	_taken = taken;
}

ostream& operator<<(ostream& stream_out, const InfCarriers& ic) {
	stream_out << ic._type << " " << ic._author << " " << ic._title << " " << ic._dateOfIssue << " " << ic._taken << "\n";
	return stream_out;
}
istream& operator>>(istream& stream_in, InfCarriers& ic) {
	stream_in >> ic._type >> ic._author >> ic._title >> ic._dateOfIssue >> ic._taken;
	return stream_in;
}