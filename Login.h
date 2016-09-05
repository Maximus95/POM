#include "UsersDAO.h"
#include "Administrator.h"

class Login {
private:
	int userID;
	string password;
	User *user;
	Administrator *admin;
	SalesManager *salesManager;
	PurchaseManager *purchaseManager;

	void displayLoginForm(){
		cout << "UserID: ";
		cin >> userID;

		int i = validateUserID();
		int option = 0; 

		if (i != -1){
			cout << "Password: ";
			cin >> password;
			validatePassword(i);
		}
		else {
			cout << " * Incorrect username!" << endl;
			cout << " 1. Try again" << endl;
			cout << " 2. Exit" << endl;
			cout << " Option: ";
			cin >> option;

			switch (option){
			case 1:{
					   displayLoginForm();
					   break;
			}
			case 2: {
						cout << " * The session is finished. Good bye!" << endl;
						break;
			}
			default: {
						 cout << " * Invalid input!" << endl;
						 break;
			}
			}
		}



	}

	int validateUserID(){
		UsersDAO usersDAO;
		vector<User> *users = NULL;
		users = usersDAO.getAllUsers();
		int option;
		bool exist = false;
		int index = 0;

		for (unsigned int i = 0; i < users->size(); i++) {
			if (userID == users->at(i).getUserID()) {
				exist = true;
				index = i;
				break;
			}
			else {
				exist = false;
			}
		}

		if (exist) {
			return index;
		}
		else {
			return -1;
		}
	}

	void validatePassword(int userIndex){
		UsersDAO usersDAO;
		vector<User> *users = NULL;
		users = usersDAO.getAllUsers();
		int option;
		bool exist = false;
		int index = userIndex;

		if (users->at(index).getPassword() == password) {
			if (users->at(index).getCategory() == "Administrator") {
				cout << "Welcome, " << users->at(index).getFirstName() << " " << users->at(index).getLastName() << "!" << endl;
				admin = new Administrator(users->at(index).getUserID(), users->at(index).getPassword(), users->at(index).getFirstName(), users->at(index).getLastName());
				admin->displayMenu();
			}
			else if (users->at(index).getCategory() == "SalesManager") {
				cout << "Welcome, " << users->at(index).getFirstName() << " " << users->at(index).getLastName() << "!" << endl;
				salesManager = new SalesManager(users->at(index).getUserID(), users->at(index).getPassword(), users->at(index).getFirstName(), users->at(index).getLastName());
				salesManager->displayMenu();
			}
			else if (users->at(index).getCategory() == "PurchaseManager") {
				cout << "Welcome, " << users->at(index).getFirstName() << " " << users->at(index).getLastName() << "!" << endl;
				purchaseManager = new PurchaseManager(users->at(index).getUserID(), users->at(index).getPassword(), users->at(index).getFirstName(), users->at(index).getLastName());
				purchaseManager->displayMenu();
			}
		}
		else {
			cout << " * Incorrect password!" << endl;
			cout << " 1. Try again" << endl;
			cout << " 2. Exit" << endl;
			cout << " Option: ";
			cin >> option;

			switch (option){
			case 1:{
					   displayLoginForm();
					   break;
			}
			case 2: {
						cout << " * The session is finished. Good bye!" << endl;
						break;
			}
			default: {
						 cout << " * Invalid input!" << endl;
						 break;
			}
			}
		}
	}


public:
	Login(){
		cout << "--- LOGIN --- " << endl;
		displayLoginForm();
	}
};