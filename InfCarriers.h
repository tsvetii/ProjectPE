#pragma once
#include <iostream>
#include "Author.h"
using namespace std;
class InfCarriers
{
public:
	enum _type { book = 0, magazine, audioCD, CDROM, cassettes, videoCassettes };
private:
	int _type;
	Author _author;
	string _title;
	string _dateOfIssue;
	bool _taken;
public:
	InfCarriers();
	InfCarriers(int, Author, string, string, bool);
	~InfCarriers();

	int GetType() const;
	void SetType(int type);

	Author GetAuthor() const;
	void SetAuthor(Author author);

	string GetTitle() const;
	void SetTitle(string title);

	string GetDateOfIssue() const;
	void SetDateOfIssue(string DateOfIssue);

	bool GetTaken() const;
	void SetTaken(bool taken);

	friend std::ostream& operator<<(std::ostream& stream_out, const InfCarriers& ic);
	friend std::istream& operator>>(std::istream& stream_in, InfCarriers& ic);

};
