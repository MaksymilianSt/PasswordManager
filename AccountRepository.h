

#ifndef PROJEKTHASLO_ACCOUNTREPOSITORY_H
#define PROJEKTHASLO_ACCOUNTREPOSITORY_H


#include <string>
#include <vector>
//#include <wsman.h>
#include "Account.h"
#include "Coder.h"

class AccountRepository {
private: Coder coder;
private:
    const std::string repoSource = "ListOfAccounts";

public:
    std::vector<Account> getAll();
    Account save(const Account &toSave)const;
private:
    std::vector<std::string> getListOfAccounts();
public:
    void update(const Account &toUpdate)const;
public:
    void deleteAccount(const Account &toDelete);
public:
    std::vector<Account> getBy(const std::string & param);


};


#endif //PROJEKTHASLO_ACCOUNTREPOSITORY_H
