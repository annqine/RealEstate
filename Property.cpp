#pragma once 
#include "Property.h"
#include <sstream>

string Property::toString() const {
    std::ostringstream result;
    result << "������� " << getPropertyType() << ": " << numRooms << " �������, ���� " << getFloorNumber() << ".\n";
    result << "����: " << price << " ��������.\n";
    result << advertiser.toString() << "\n";
    return result.str();
}

//string Property::toString() const {
//    return "�����: " + address.toString() + "\n"
//        + "���������� ������: " + to_string(numRooms) + ", ����: " + to_string(price) + "\n"
//        + "�������?: " + (forRent ? "Yes" : "No") + "\n"
//        + "����� ��������: " + to_string(houseNumber) + ", ����� ��������: " + to_string(floorNumber) + "\n"
//        + "������������: " + advertiser.toString();
//}