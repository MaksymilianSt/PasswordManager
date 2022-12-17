//
// Created by Maximiliano on 13.12.2022.
//

#ifndef PROJEKTHASLO_ACCOUNT_H
#define PROJEKTHASLO_ACCOUNT_H
#include<string>





class Account {
private:
    std::string name;
    std::string password;
    std::string category;
    std::string login;
    std::string page;
public:
    std::string toString();

public:
    const std::string getName() const;

    void setName(const std::string &name);

    const std::string &getPassword() const;

    void setPassword(const std::string &password);

    const std::string &getCategory() const;

    void setCategory(const std::string &category);

    const std::string &getLogin() const;

    void setLogin(const std::string &login);

    const std::string &getPage() const;

    void setPage(const std::string &page);

};


#endif //PROJEKTHASLO_ACCOUNT_H
