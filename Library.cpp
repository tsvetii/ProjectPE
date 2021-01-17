#include "Library.h"
#include "InfCarriers.h"
#include "Author.h"
int main() {
	Library lib;
	lib.begin();
	return 0;
}

void Library::loadAuthors(vector<Author>& vect, string filename) {
	ifstream file;															 
	file.open(filename, ios::in);
	Author newAuthor;
	while (file.is_open()) {
		if (file.eof()) break;
		file >> newAuthor;
		vect.push_back(newAuthor);
	}
	vect.pop_back();
	file.close();
}

void Library::saveAuthors(vector<Author>& vect, string filename) {
	ofstream file;													
	file.open(filename, ios::out);
	for (int i = 0; i < vect.size(); i++) {
		file << vect[i];
	}
	file.close();
}

void Library::loadInfCarriers(vector<InfCarriers>& vect, string filename) {
	ifstream file;					
	file.open(filename, ios::in);   
	InfCarriers newCarrier;
	while (file.is_open()) {
		if (file.eof()) break;
		file >> newCarrier;
		vect.push_back(newCarrier);    
	}
	vect.pop_back();
	file.close();
}

void Library::saveInfCarriers(vector<InfCarriers>& vect, string filename) {
	ofstream file;						
	file.open(filename, ios::out);     
	for (int i = 0; i < vect.size(); i++) {
		file << vect[i];
	}
	file.close();
}

void Library::createAuthor() {						

	cout << "Enter author's name: \n";
	string name;
	cin >> name;

	cout << "Enter author's birthdate: \n";
	string birthdate;
	cin >> birthdate;

	cout << "Choose author's type of job: \n 1. Musician \n 2. Actor \n 3. Writer \n 4. Journalist \n ";
	int choice = -1;
	while (choice < 1 || choice > 4)
	{
		cin >> choice;
		if (choice > 0 && choice < 5)
			break;
		cout << "Invalid choice. \t Choose again!\t\n";

	}
	Author newAuthor(name, birthdate, choice);
	authors.push_back(newAuthor);
	saveAuthors(authors, authorsFile);


}

void Library::createInfCarrier() {
	cout << "Choose a type: \n 1. Book \n 2. Magazine \n 3. Audio-CD \n 4. CD-ROM \n 5. Cassettes \n 6. VideoCassettes \n ";
	int type = -1;
	while (type < 1 || type > 6)
	{
		cin >> type;
		if (type > 0 && type < 7)
			break;
		cout << "Invalid choice. \t Choose again!\t\n";

	}

	cout << "Choose an author: \n";
	string jobtypes[] = { "musician", "actor", "writer", "journalist" };
	for (int i = 0; i < authors.size(); i++)
	{																			
		cout << "Choose " << i << " for: " << jobtypes[authors[i].GetTypeOfJob() - 1] << " " << authors[i].GetName() << endl;
	}
	int choice = -1;
	while (choice < 0 || choice > 4)
	{
		cin >> choice;
		if (choice >= 0 && choice < 5)
			break;
		cout << "Invalid choice. \t Choose again!\t\n";

	}

	cout << "Enter a title: \n";
	string title;
	cin >> title;

	cout << "Enter a date of issue: \n";
	string date;
	cin >> date;

	InfCarriers newCarrier(type, authors[choice], title, date, false);
	infCarriers.push_back(newCarrier);
	saveInfCarriers(infCarriers, infCarriersFile);
}

void Library::checkAvailability()
{
	cout << "Avaliable:\n";
	for (int i = 0; i < infCarriers.size(); i++) {
		if (infCarriers[i].GetTaken() == false) {
			cout << infCarriers[i].GetTitle() << " by " << infCarriers[i].GetAuthor().GetName() << endl;
		}
	}
}

void Library::rent() {
	for (int i = 0; i < infCarriers.size(); i++) {
		if (infCarriers[i].GetTaken() == false) {
			cout << i << ". " << infCarriers[i].GetTitle() << " by " << infCarriers[i].GetAuthor().GetName() << endl;
		}
	}
	int ans = -1;
	int avail = 0; 
	for (int i = 0; i < infCarriers.size(); i++) {
		if (infCarriers[i].GetTaken() == false) {
			avail++;
		}
	}
	
	while (ans < 0 || ans > avail)
	{
		cout << "Please choose: ";
		cin >> ans;
		if (ans >= 0 && ans <= avail)
			break;
		cout << "Invalid choice. \t Choose again!\t\n";
	}
	
	cout << "You rented " << infCarriers[ans].GetTitle() << " by " << infCarriers[ans].GetAuthor().GetName() << endl;
	infCarriers[ans].SetTaken(true);
	saveInfCarriers(infCarriers, infCarriersFile);
}

void Library::returnCarrier() {
	for (int i = 0; i < infCarriers.size(); i++) {
		if (infCarriers[i].GetTaken() == true) {
			cout << i << ". " << infCarriers[i].GetTitle() << " by " << infCarriers[i].GetAuthor().GetName() << endl;
		}
	}
	cout << "What are you returning: ";
	int ans = -1;
	int avail = 0;
	for (int i = 0; i < infCarriers.size(); i++) {
		if (infCarriers[i].GetTaken() == true) {
			avail++;
		} 
	}
	while (ans < 0 || ans>avail)		
	{
		cin >> ans;
		if (ans >= 0 && ans <= avail)
			break;
		cout << "Invalid choice. \t Choose again!\t\n";
	}

	infCarriers[ans].SetTaken(false);
	saveInfCarriers(infCarriers, infCarriersFile);
}

void Library::begin() {
	loadAuthors(authors, authorsFile);
	loadInfCarriers(infCarriers, infCarriersFile);
	int input;
	bool menu = true;
	while (menu != false) {
		cout << "\n\n\n````````````````````````````````````````\n";
		cout << "`                 MENU                 `\n ";
		cout << "````````````````````````````````````````\n";
		cout << " 1. Create author\n";
		cout << " 2. Create information carrier\n";
		cout << " 3. Rent\n";
		cout << " 4. Return\n";
		cout << " 5. Check avaliable resourses\n";
		cout << " 6. Exit\n";
		cout << " \nEnter your choice.\n";

		cin >> input;

		switch (input)
		{
		case 1:
			createAuthor();
			break;
		case 2:
			createInfCarrier();
			break;
		case 3:
			rent();
			break;
		case 4:
			returnCarrier();
			break;
		case 5:
			checkAvailability();
			break;
		case 6:
			menu = false;
			break;
		default:
			cout << "Not a valid choice. \n";
			cout << "Choose again.\n";
			cin >> input;
			break;
		}
	}
}




