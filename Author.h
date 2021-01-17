#pragma once
#include <iostream>
#include <string>
using namespace std;
class Author
{
public:
	enum _typeOfJob { musician = 0, actor, writer, journalist };
private:
	string _name;
	string _birthDate;
	int _typeOfJob;

public:
	Author();						
	Author(string, string, int);
	~Author();						

	string GetName() const;			
	void SetName(string name);

	string GetBirthDate() const;
	void SetBirthDate(string birthDate);

	int GetTypeOfJob() const;
	void SetTypeOfJob(int typeOfJob);

	friend ostream& operator<<(ostream& stream_out, const Author& author);  
	friend istream& operator>>(istream& stream_in, Author& author);			

};

