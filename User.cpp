#include "User.h"
#include <sstream>

string User::toString() const {
    std::ostringstream result;
    result << "���������� ����������: " << login << " " << number;
    if (isBroker) {
        result << " (������)"; }
    result << ".";
    return result.str(); }

//string User::toString() const {
//	string userType = (isBroker) ? "������" : "���������� ����";
//	return "��� ������������: " + login +
//		"\n������: " + password +
//		"\n����� ��������: " + number +
//		"\n��� ������������: " + userType;}
