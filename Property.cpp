#pragma once 
#include "Property.h"
#include <sstream>

string Property::toString() const {
    std::ostringstream result;
    result << "Сдается " << getPropertyType() << ": " << numRooms << " комнаты, этаж " << getFloorNumber() << ".\n";
    result << "Цена: " << price << " долларов.\n";
    result << advertiser.toString() << "\n";
    return result.str();
}

//string Property::toString() const {
//    return "Адрес: " + address.toString() + "\n"
//        + "Количество комнат: " + to_string(numRooms) + ", Цена: " + to_string(price) + "\n"
//        + "Сдается?: " + (forRent ? "Yes" : "No") + "\n"
//        + "Номер телефона: " + to_string(houseNumber) + ", Номер квартиры: " + to_string(floorNumber) + "\n"
//        + "Пользователь: " + advertiser.toString();
//}