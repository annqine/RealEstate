#pragma once
#include <iostream>
#include "RealEstate.h"
#include "Address.h"
#include "User.h"
#include "Property.h"
#include <Windows.h>
#include <set>
#include <sstream>

using namespace std;

RealEstate::RealEstate() {
    Address address1("Киев", "Богдана Хмельницкого");
    Address address2("Днепр", "Карла Маркса");
    Address address3("Львов", "Краковская");
    Address address4("Кривой Рог", "95 квартал");
    Address address5("Днепр", "8 марта");
    Address address6("Киев", "Владимирская");
    Address address7("Киев", "Петра Сагайдачного");
    Address address8("Львов", "Шевченко");
    Address address9("Кривой Рог", "Мира");
    Address address10("Киев", "Большая Васильковская");

    addresses.push_back(address1);
    addresses.push_back(address2);
    addresses.push_back(address3);
    addresses.push_back(address4);
    addresses.push_back(address5);
    addresses.push_back(address6);
    addresses.push_back(address7);
    addresses.push_back(address8);
    addresses.push_back(address9);
    addresses.push_back(address10);

    User admin("a", "an_1", "0511111111", false);
    users.push_back(admin);
}
string RealEstate::toString() const {
    std::ostringstream result;

    result << "Пользователи:\n";
    for (const User& user : users) {
        result << user.toString() << "\n";}

    result << "\nОбъекты недвижимости:\n";
    for (const Property& property : properties) {
        result << property.toString() << "\n";}

    return result.str();
};
void RealEstate::createUser(){
    string username, password, phoneNumber;
    unsigned int isBroker;
    std::cin.ignore(); 

    std::cout << "Введите желаемое имя пользователя: ";
    getline(std::cin, username);
    while (isUsernameTaken(username)) {
        std::cout << "Имя пользователя уже занято. Введите другое имя: ";
        getline(std::cin, username);}
    std::cout << "Введите надежный пароль (содержащий цифру и символ $,% или _): ";
    getline(std::cin, password);
    while (!isPasswordStrong(password)) {
        std::cout << "Пароль не надежный. Введите пароль снова: ";
        getline(std::cin, password);}
    std::cout << "Введите номер телефона (длина 10 цифр, начинается с 05): ";
    getline(std::cin, phoneNumber);
    while (!isValidPhoneNumber(phoneNumber)) {
        std::cout << "Неверный номер телефона. Введите номер телефона снова: ";
        getline(std::cin, phoneNumber);}
    std::cout << "Вы брокер? (1 - Да, 0 - Нет): ";
    std::cin >> isBroker;
    while (isBroker != 1 && isBroker != 0) {
        std::cout << "Неверный выбор. Повторите ввод: ";
        std::cin >> isBroker;
    };

    User newUser(username, password, phoneNumber, isBroker);
    users.push_back(newUser);
    std::cout << "Пользователь успешно создан!" << endl;
}

//валидация для метода createUser()
bool RealEstate::isUsernameTaken(const string& username) {
    char ch = username[0]; if (std::isspace(ch)) { return false; } 
    for ( auto& user : users) {
        if (user.getLogin() == username) {
            return true;
        }
    }
    return false;
}
bool RealEstate::isPasswordStrong(const string& password) {
    bool hasDigit = false;
    bool hasSpecialChar = false;

    for (char ch : password) {
        if (std::isdigit(ch)) {
            hasDigit = true;
        } else if (ch == '$' || ch == '%' || ch == '_') {
            hasSpecialChar = true;
        } else if (std::isspace(ch)) {  // Проверка на пробел
            return false;}}
    return hasDigit && hasSpecialChar;}
bool RealEstate::isValidPhoneNumber(const string& phoneNumber) {
    if (phoneNumber.length() != 10 || phoneNumber.substr(0, 2) != "05") {
        return false; }
    for (char ch : phoneNumber) {
        if (!std::isdigit(ch) || std::isspace(ch)) {  // Проверка на пробел
            return false; }}
    return true; }

User* RealEstate::loginUser() {
    string username, password;

    std::cin.ignore();
    std::cout << "Введите имя пользователя: ";
    getline(std::cin, username);

    std::cout << "Введите пароль: ";
    getline(std::cin, password);
    for (auto& user : users) {
        if (user.getLogin() == username && user.getPassword() == password) {
            return &user; }}
    return nullptr;
}
/*User* RealEstate::loginUser() {
    string username, password;

    std::cout << "Введите имя пользователя: ";
    getline(std::cin, username);

    std::cout << "Введите пароль: ";
    getline(std::cin, password);

    auto it = find_if(users.begin(), users.end(), [&]( User& user) {
        return user.getLogin() == username && user.getPassword() == password;
        });

    if (it != users.end()) {
        return &(*it); 
    }

    return nullptr;
}*/
// Функция для вывода уникальных городов
void RealEstate::displayUniqueCities() {
    set<string> uniqueCities;

    for (Address& address : addresses) {
        uniqueCities.insert(address.getCity()); }

    std::cout << "Список городов:\n";
    for (const string& city : uniqueCities) {
        std::cout << city << endl; }
};
bool RealEstate::postNewProperty(User* loggedInUser) {
    if (loggedInUser->getIsBroker() == true && properties.size() >= 10) {
        std::cout << "Вы достигли своего лимита!" << endl;
        return false;
    }
    if (loggedInUser->getIsBroker() == false && properties.size() >= 3) {
        std::cout << "Вы достигли своего лимита!" << endl;
        return false;
    }

    displayUniqueCities();
    string selectedCity;
    std::cin.ignore();
    std::cout << "Введите название города из списка: ";
    getline(std::cin, selectedCity);
    std::cout << endl;

    auto cityIterator = find_if(addresses.begin(), addresses.end(),
        [selectedCity](Address& address) { return address.getCity() == selectedCity; });
    if (cityIterator == addresses.end()) { return false; }

    vector<string> streetsInCity;
    for (Address& address : addresses) {
        if (address.getCity() == selectedCity) {
            streetsInCity.push_back(address.getStreet());}}

    std::cout << "Список улиц в городе " << selectedCity << ":\n";
    for (const string& street : streetsInCity) {
        std::cout << street << endl;}

    string selectedStreet;
    std::cout << "Введите название улицы из списка: ";
    getline(std::cin, selectedStreet);
    std::cout << endl;

    auto streetIterator = find(streetsInCity.begin(), streetsInCity.end(), selectedStreet);
    if (streetIterator == streetsInCity.end()) { return false; }

    unsigned int propertyType;
    std::cout << "Выберите тип недвижимости (1 - квартира, 2 - пентхаус, 3 - частный дом): ";
    std::cin >> propertyType;
    while (propertyType < 1 || propertyType > 3) {
        std::cout << "Неверный выбор. Выберите тип недвижимости (1 - квартира, 2 - пентхаус, 3 - частный дом): ";
        std::cin >> propertyType;
    }
    unsigned int floor = 1;
    if (propertyType == 1) {
        std::cout << "Введите этаж квартиры: ";
        std::cin >> floor;
    }

    unsigned int numberOfRooms, propertyNumber;
    std::cout << "Введите количество комнат: ";
    std::cin >> numberOfRooms;
    std::cout << "Введите номер собственности: ";
    std::cin >> propertyNumber;
    unsigned int isForRent;
    std::cout << "Недвижимость сдается? (1 - да, 0 - нет): ";
    std::cin >> isForRent;
    while (isForRent != 1 && isForRent != 0) {
        std::cout << "Неверный выбор. Повторите ввод: ";
        std::cin >> isForRent;
    };
    double price;
    std::cout << "Введите цену на недвижимость: ";
    std::cin >> price;

    Property newProperty(selectedCity, selectedStreet, numberOfRooms, price, propertyType, isForRent, propertyNumber, floor, *loggedInUser);
    properties.push_back(newProperty);
    std::cout << "Недвижимость успешно добавлена!" << endl;
    return true; }
void RealEstate::printAllProperties() {
    if (properties.size() == 0) {
        std::cout << "Нет опубликованных свойств." << std::endl; }
    else {
        std::cout << "Список всех свойств в системе:" << std::endl;
        for (const auto& property : properties) {
            std::cout << property.toString() << std::endl; }}
}
void RealEstate::printAllProperties(User* loggedInUser) {
    std::cout << "Активы, опубликованные пользователем " << loggedInUser->getLogin() << ":" << endl;

    if (properties.size() == 0) {
        std::cout << "Нет опубликованных свойств." << std::endl; }
    else {
        std::cout << "Список всех свойств в системе:" << std::endl;
        for (const auto& property : properties) {
            std::cout << property.toString() << std::endl; }}
}
void RealEstate::removeProperty(User* loggedInUser) {
    if (properties.size() == 0) {
        std::cout << "У Вас нет опубликованных реклам" << endl; return;
    }
    else {
        std::cout << "Выберите свойство для удаления:\n";
        for (int i = 0; i < properties.size(); i++) {
            if (properties[i].getAdvertiser().getLogin() == loggedInUser->getLogin()) {
                cout << i + 1 << ") " << properties[i].toString() << "\n"; }}

        int choice;
        std::cout << "Введите номер свойства для удаления: ";
        std::cin >> choice;

        if (choice > 0 && choice <= properties.size()) {
            properties.erase(properties.begin() + choice - 1);
            std::cout << "Свойство успешно удалено.\n"; }
        else {
            std::cout << "Неверный выбор.\n"; }}}
vector<Property> RealEstate::searchProperties() {
    vector<Property> resultProperties;

    unsigned int isForRent;
    std::cout << "Сдается или продается? (1 - сдается, 0 - продается, 999 - любое): ";
    std::cin >> isForRent;

    unsigned int propertyType;
    std::cout << "Какой тип недвижимости вы ищете? (1 - квартира, 2 - пентхаус, 3 - частный дом, 999 - любой): ";
    std::cin >> propertyType;

    unsigned int numRooms;
    std::cout << "Желаемое количество комнат (введите 999, если не имеет значения): ";
    std::cin >> numRooms;

    double minPrice, maxPrice;
    std::cout << "Желаемый ценовой диапазон (минимальный и максимальный, введите 999, если не имеет значения): ";
    std::cin >> minPrice >> maxPrice;

    for (const Property& property : properties) {
        if ((isForRent == 999 || property.getForRent() == isForRent) &&
            (propertyType == 999 || property.getPropertyType() == propertyType) &&
            (numRooms == 999 || property.getNumRooms() == numRooms) &&
            (minPrice == 999 || (property.getPrice() >= minPrice && property.getPrice() <= maxPrice))) {
            resultProperties.push_back(property);}}

    return resultProperties; }

RealEstate realEstate;

int main() {
    SetConsoleCP(1251); // Установка кодовой страницы ввода на 1251 (русская)
    SetConsoleOutputCP(1251); // Установка кодовой страницы вывода на 1251 (русская)
    
    unsigned int choice;
    do {
        cout << "Главное меню:\n";
        cout << "1 - Создать учетную запись\n";
        cout << "2 - Войти в существующую учетную запись\n";
        cout << "3 - Завершить программу\n";
        cout << "Выберите: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            realEstate.createUser();
            break;
        case 2:
            User * currentUser;
               currentUser = realEstate.loginUser();
               if (currentUser != nullptr) {
                   realEstate.displayMainMenu(currentUser);
               } else {
                   cout << "Неверное имя пользователя или пароль.\n"; }
            system("cls");
            continue;
            break;
        case 3:
            cout << "Программа завершена.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            system("cls");
            continue;
        }
    } while (choice != 3);

    return 0;
}

void RealEstate::displayMainMenu(User* loggedInUser) {
    if (loggedInUser == nullptr) {
        cout << "Пользователь не вошел в систему. Войдите сначала." << endl; }

    cout << "Добро пожаловать, " << loggedInUser->getLogin() << "!" << endl;
    RealEstate realEstate;
    unsigned int choice;
    bool returnToMainMenu = false;
    do {
        cout << "Главное меню:\n";
        cout << "1 - Разместите новую недвижимость\n";
        cout << "2 - Убрать рекламу на объекте\n";
        cout << "3 - Просмотреть все активы в системе\n";
        cout << "4 - Просмотреть все активы, опубликованные пользователем\n";
        cout << "5 - Поиск недвижимости по параметрам\n";
        cout << "6 - Отключитесь и вернитесь в главное меню\n";
        cout << "Выберите: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            postNewProperty(loggedInUser);
            system("cls");
            break;
        case 2:
            removeProperty(loggedInUser);
            system("cls");
            break;
        case 3:
            printAllProperties();
            break;
        case 4:
            printAllProperties(loggedInUser);
            break;
        case 5:
            searchProperties();
            break;
        case 6:
            system("cls");
            returnToMainMenu = true;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            system("cls");
        }
    } while (!returnToMainMenu);

}

