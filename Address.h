#pragma once
#include <string>

using namespace std;

class Address
{
protected:
	string city, street;
public:
	Address(string city, string street) : city(city), street(street) {};
	~Address() {};

	string getCity() const { return city; }
	string getStreet() const { return street; }
	string toString() const;
};