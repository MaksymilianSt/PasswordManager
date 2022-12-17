//
// Created by Maximiliano on 15.12.2022.
//

#ifndef PROJEKTHASLO_SERVICE_H
#define PROJEKTHASLO_SERVICE_H


#include "CategoryRepository.h"
#include "AccountRepository.h"
#include "Validator.h"

class Service {
private:
        CategoryRepository categoryRepository;
        AccountRepository accountRepository;
        Validator validator;

public:
    void addCategory();
public:
    void showAll();
public:
    void addAccount();

private:
    Account createAccount(bool generatePassword);
public:
    void editAccount();
public:
    void deleteAccount();
public:
    void deleteCategory();
public:
    void getAccountBy();
public:
    void getSortedAcc();


};


#endif //PROJEKTHASLO_SERVICE_H
