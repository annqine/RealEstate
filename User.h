#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
protected:
	string login, password, number;
	bool isBroker = false;

public:
	User(string login, string password, string number, bool isBroker)
		: login(login), password(password), number(number), isBroker(isBroker) {};
	~User() {};

	string getLogin() const { return login; };
	string getPassword() const { return password; };
	string getNumber() const { return number; };
	void setLogin(string l) { login = l; };
	void setPassword(string p) { password = p; };
	bool getIsBroker() const { return isBroker; };

	string toString() const;
};


