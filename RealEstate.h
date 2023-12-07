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

    //��������� ���������� ���� ��� ����� � ���������
    bool isUsernameTaken(const string& username);
    bool isPasswordStrong(const string& password);
    bool isValidPhoneNumber(const string& phoneNumber);
    
    User* loginUser();  //+ ����� ������ 

    //�������� ����
    void displayMainMenu(User* loggedInUser);

    //������ ��������� ����
    bool postNewProperty(User* loggedInUser);
    void displayUniqueCities();//����� ������ ������� ������ � ������ ���� ��� �������
    void printAllProperties();
    void printAllProperties(User* loggedInUser);
    void removeProperty(User* loggedInUser);
    vector<Property> searchProperties();
    //RealEstate(){
    //    Address address1("����-����", "���������");
    //    addresses.push_back(address1);
    //    Address address2("����-����", "���-������");
    //    addresses.push_back(address2);
    //    Address address3("���������", "����");
    //    addresses.push_back(address3);
    //    Address address4("���������", "���� �����");
    //    addresses.push_back(address4); }
};

