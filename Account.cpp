//
// Created by Maximiliano on 13.12.2022.
//

#include "Account.h"

const std::string Account::getName() const {
    return name;
}

void Account::setName(const std::string &name) {
    Account::name = name;
}

const std::string &Account::getPassword() const {
    return password;
}

void Account::setPassword(const std::string &password) {
    Account::password = password;
}

const std::string &Account::getCategory() const {
    return category;
}

void Account::setCategory(const std::string &category) {
    Account::category = category;
}

const std::string &Account::getLogin() const {
    return login;
}

void Account::setLogin(const std::string &login) {
    Account::login = login;
}

const std::string &Account::getPage() const {
    return page;
}

void Account::setPage(const std::string &page) {
    Account::page = page;
}

std::string Account::toString() {
    return "nazwa: "+ name +"\n" +
            "haslo: "+ password +"\n" +
            "kategoria: "+ category +"\n" +
            "login: "+ login +"\n" +
            "strona: "+ page +"\n" ;
}
