#pragma once
#include <string>
#include "Address.h"
#include "User.h"

using namespace std;

class Property
{
protected:
    Address address;
    unsigned int numRooms;
    double price;
    unsigned int propertyType;
    bool forRent;
    unsigned int houseNumber;
    unsigned int floorNumber;
    User advertiser;
public:
    Property(string& city, string& street, unsigned int numRooms, double price, unsigned int propertyType, bool forRent, unsigned int houseNumber, unsigned int floorNumber, User advertiser)
        : address(city, street), numRooms(numRooms), price(price), propertyType(propertyType), forRent(forRent),
        houseNumber(houseNumber), floorNumber(floorNumber), advertiser(advertiser) {};
	~Property() {};

    string toString() const;

    Address getAddress() const { return address; }
    unsigned int getNumRooms() const { return numRooms; }
    double getPrice() const { return price; }
    unsigned int getPropertyType() const { return propertyType; }
    bool getForRent() const { return forRent; }
    unsigned int getHouseNumber() const { return houseNumber; }
    unsigned int getFloorNumber() const { return floorNumber; }
    User getAdvertiser() const { return advertiser; }
}; 
