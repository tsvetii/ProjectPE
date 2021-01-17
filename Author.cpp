#include "Author.h"
Author::Author() {													
	_name = "Unknown";
	_birthDate = "Unknown";
	_typeOfJob = -1;
}

Author::Author(string name, string birthDate, int typeOfJob) {		
	_name = name;
	_birthDate = birthDate;
	_typeOfJob = typeOfJob;
}

Author::~Author() {}


string Author::GetName() const {
	return _name;
}
void Author::SetName(string name) {
	_name = name;
}


string Author::GetBirthDate() const {
	return _birthDate;
}
void Author::SetBirthDate(string birthDate) {
	_birthDate = birthDate;
}


int Author::GetTypeOfJob() const {
	return _typeOfJob;
}
void Author::SetTypeOfJob(int typeOfJob) {
	_typeOfJob = typeOfJob;
}

ostream& operator<<(ostream& stream_out, const Author& author) {										
	stream_out << author._name << " " << author._birthDate << " " << author._typeOfJob << "\n";
	return stream_out;
}
istream& operator>>(istream& stream_in, Author& author) {												
	stream_in >> author._name >> author._birthDate >> author._typeOfJob;
	return stream_in;
}