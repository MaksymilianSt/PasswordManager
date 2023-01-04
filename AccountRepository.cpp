
#include <fstream>
#include <iostream>
#include "AccountRepository.h"
#include "Account.h"
#include "string"

/**
 *
 * @return vector of all accounts stored in the file
 */
std::vector<Account> AccountRepository::getAll() {
    std::vector<std::string> toAccount = getListOfAccounts();
    std::vector<Account> accounts;
    for(int i = 0 ; i<toAccount.size();i++) {
        std::ifstream File(toAccount[i], std::ios::app);
        if (File.is_open()) {
            std::string line;
            int indexOfLine = 0;
            Account acc;
            while (std::getline(File, line)) {

                if(indexOfLine==1)acc.setName(coder.deCode(line));
                if(indexOfLine==2)acc.setPassword(coder.deCode(line));
                if(indexOfLine==3)acc.setCategory(coder.deCode(line));
                if(indexOfLine==4)acc.setLogin(coder.deCode(line));
                if(indexOfLine==5) acc.setPage(coder.deCode(line));
            indexOfLine++;
            }
            accounts.push_back(acc);
            File.close();
        }
    }



    return accounts;
}

/**
 * function saves account to the new file  and timestamp
 * @param toSave account to be saved in the file
 * @return account saved in the file
 */
Account AccountRepository::save(const Account &toSave) const{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );



    std::ofstream File( toSave.getName() , std::ios::app);
    if (File.is_open()) {
        File << asctime (timeinfo) ;
        File << coder.code(toSave.getName()) << "\n";
        File << coder.code(toSave.getPassword()) << "\n";// code password before
        File << coder.code(toSave.getCategory()) << "\n";
        File << coder.code(toSave.getLogin()) << "\n";
        File << coder.code(toSave.getPage() )<< "\n";
        File.close();

        std::ofstream ListFile( repoSource , std::ios::app);
        if (ListFile.is_open()) {
            ListFile << toSave.getName()<< "\n";

            ListFile.close();

        }
    }


    return toSave;
}
/**
 *
 * @return vector of all account's (files) names that has been saved
 */
std::vector<std::string> AccountRepository::getListOfAccounts() {
    std::vector<std::string> list;
    std::ifstream File(repoSource);
    if(File.is_open()){
        std::string line ;
        while(std::getline(File,line)){

            list.push_back(line);
        }
        File.close();
    }
    return list;
}
/**
 * function updates given account and timestamp
 * @param toUpdate account to update
 */
void AccountRepository::update(const Account &toUpdate)const {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);


    std::ofstream File(toUpdate.getName());
    if (File.is_open()) {
        File << asctime(timeinfo);
        File << coder.code(toUpdate.getName()) << "\n";
        File << coder.code(toUpdate.getPassword()) << "\n";
        File << coder.code(toUpdate.getCategory()) << "\n";
        File << coder.code(toUpdate.getLogin()) << "\n";
        File << coder.code(toUpdate.getPage()) << "\n";
        File.close();

    }
}
/**
 * function deletes account , it deletes the file that account has been stored in,  and delete it from the list of all accounts (files)
 * @param toDelete account to delete
 */
void AccountRepository::deleteAccount(const Account &toDelete) {

    if(remove((toDelete.getName()).c_str())==0){
        std::cout<< " haslo : " <<  toDelete.getName() << " usuniete\n";
    }


    std::vector<std::string> listOfAcc = getListOfAccounts();
    for(int i = 0 ; i < listOfAcc.size();i++){
        if(listOfAcc.at(i) == toDelete.getName()){
            listOfAcc.at(i)="";
        }
    }

    std::ofstream ListFile( repoSource );
    if (ListFile.is_open()) {
        for(std::string c : listOfAcc ){
            ListFile << c << "\n";
        }
        ListFile.close();

    }

}
/**
 *
 * @param param - information that is being search in the accounts
 * @return vector of accounts that contains specific param
 */
std::vector<Account> AccountRepository::getBy(const std::string &param)  {
    std::vector<Account> allAcc = getAll();
    std::vector<Account> byParam;
    for(Account a : allAcc){
        if(a.toString().find(param)!=std::string::npos)
            byParam.push_back(a);
    }

    return byParam;
}


