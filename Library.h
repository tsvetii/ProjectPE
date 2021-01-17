#pragma once
#include "InfCarriers.h"
#include "Author.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Library
{
private:
	string authorsFile = "Authors.txt";
	string infCarriersFile = "InformationCarriers.txt";
	vector <Author> authors;								
	vector <InfCarriers> infCarriers;						
public:
	void begin();
private:
	void loadAuthors(vector<Author>& vect, string filename);
	void loadInfCarriers(vector<InfCarriers>& vect, string filename);
	void saveAuthors(vector<Author>& vect, string filename);
	void saveInfCarriers(vector<InfCarriers>& vect, string filename);
	void createAuthor();
	void createInfCarrier();
	void checkAvailability();
	void rent();
	void returnCarrier();
};

