#include "User.h"
#include <sstream>

string User::toString() const {
    std::ostringstream result;
    result << "Контактная информация: " << login << " " << number;
    if (isBroker) {
        result << " (маклер)"; }
    result << ".";
    return result.str(); }

//string User::toString() const {
//	string userType = (isBroker) ? "брокер" : "физическое лицо";
//	return "Имя пользователя: " + login +
//		"\nПароль: " + password +
//		"\nНомер телефона: " + number +
//		"\nТип пользователя: " + userType;}
