#pragma once
#include <vector>
#include "Address.h"
#include "User.h"
#include "Property.h"


using namespace std;

class RealEstate
{
protected:
	vector<User> users;
	vector<Property> properties;
	vector<Address> addresses;

public:
    RealEstate();
	~RealEstate() {};

    string toString() const;

    void createUser();

    //валидация начального меню для входа в программу
    bool isUsernameTaken(const string& username);
    bool isPasswordStrong(const string& password);
    bool isValidPhoneNumber(const string& phoneNumber);
    
    User* loginUser();  //+ новый челикс 

    //основное меню
    void displayMainMenu(User* loggedInUser);

    //методы основного меню
    bool postNewProperty(User* loggedInUser);
    void displayUniqueCities();//метод вывода каждого города о одному разу без повтора
    void printAllProperties();
    void printAllProperties(User* loggedInUser);
    void removeProperty(User* loggedInUser);
    vector<Property> searchProperties();
    //RealEstate(){
    //    Address address1("Тель-Авив", "Дизенгофф");
    //    addresses.push_back(address1);
    //    Address address2("Тель-Авив", "Бен-Гурион");
    //    addresses.push_back(address2);
    //    Address address3("Иерусалим", "Яффо");
    //    addresses.push_back(address3);
    //    Address address4("Иерусалим", "Кинг Давид");
    //    addresses.push_back(address4); }
};

