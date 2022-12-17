//
// Created by Maximiliano on 15.12.2022.
//

#include <iostream>
#include "Service.h"
#include "algorithm"
#include "cstring"
void Service::addCategory(){
    std::string toSave;
    std::cout<< "podaj nazwe kategorii : ";
    std::cin>> toSave;
    categoryRepository.saveCategory(toSave);
}

void Service::addAccount() {
    Account created;

    int decision;
    do{
        std::cout <<"\tTWORZENIE KONTA \n";
        std::cout <<"wybierz 1 jesli chcesz wprowadzic wlasne haslo \n";
        std::cout <<"wybierz 2 jesli chcesz wygenerowac haslo \n";
        std::cout <<"decyzja : ";

        std::cin >> decision;
        switch(decision){
            case 1 :{
              created = createAccount(false);
              break;

            }
            case 2:{
                created = createAccount(true);
                break;
            }

        }
    }while(!(decision==1 || decision== 2));
    accountRepository.save(created);

}

Account Service::createAccount(bool generatePassword) {
    //name distinct
    Account created;

    std::string name="";
    bool distinct ;
    std::vector<Account> accounts = accountRepository.getAll();
    do {
        distinct = true;

        std::cout << "\n podaj nazwe (jesli chcesz aby haslo zostalo umieszczone w konkretnym folderze wpisz jego  sciezke  tutaj) :";
        std::cin >> name;

        for(Account a : accounts) {
            if (a.getName() == name) {
                distinct = false;
            }
        }

        if(!distinct)
            std::cout << "\nnazwa juz wystepuje(nazwa musi byc rozroznialna)"<< std::endl;

        if(name.empty())
            std::cout << "\nnazwa nie może być pusta"<< std::endl;

    }while(name.empty()||!distinct);
    created.setName(name);




    std::string password="";

    if(!generatePassword) {

        do {
            bool passExists= false;
            std::vector<Account> accounts = accountRepository.getAll();
            std::cout << "\npodaj haslo :";
            std::cin >> password;
            for(Account a : accounts){
                if(a.getPassword()==password){
                    passExists= true;
                }
            }
            if(passExists)
                std::cout<< "\ntakie haslo juz istnieje";
            if(validator.validatePassword(password))
                std::cout << "\n haslo bezpieczne ";
            else
                std::cout<< "\n haslo malo bezpieczne";


        } while (password.empty());
    }else{
        int size=-1;
        while(size <2){
            std::cout<< "\n Podaj ilosc znakow do wygenerowania hasla :";
            std::cin >> size;
            if(size<2)
                std::cout<< "\t\nhaslo musi zawierac conajmniej 1 znak!";
        }


        int greatSigns;
        std::cout<< "\n wpisz 1 jesli ma zawierac wielkie litery : ";
        std::cin >> greatSigns;
        int specialSigns;
        std::cout<< "\n wpisz 1 jesli ma zawierac znaki specialne : ";
        std::cin >> specialSigns;
        password = validator.generatePassword(size,greatSigns==1, specialSigns==1);



        //generator
    }
    created.setPassword(password);

    //category
    int cat = -1;
    std::vector<std::string> categories = categoryRepository.getAll();
    std::cout<< "\ndostepne kategorie :"<< std::endl;
    do {
        for(int i = 0 ; i<categories.size();i++){
            std::cout<<"\t"<<  i << ": "<<categories.at(i)<< "\n";
        }

        std::cout << "\nwybierz numer kategorii :";
        std::cin >> cat;
        if(cat<0 || cat>= categories.size())
            std::cout << "\nwybrano zla liczbe! (wybierz liczbe z zakresu 0-"<<categories.size()-1<<")"<< std::endl;

    }while(cat<0 || cat>= categories.size());
    created.setCategory(categories.at(cat));
//login
    std::string login="";
    int addLogin;
    std::cout<<"\n jesli chcesz podac login wcisnij 1 :" ;
    std::cin>> addLogin;
    if(addLogin== 1) {
        std::cout << "\npodaj login :";
        std::cin >> login;
    }
    created.setLogin(login);
//page
    std::string page="";
    int addPage;
    std::cout<<"\n jesli chcesz podac strone wcisnij 1 :" ;
    std::cin>> addPage;
    if(addPage== 1) {
        std::cout << "\npodaj strone :";
        std::cin >> page;
    }
    created.setPage(page);
    return created;
}

void Service::editAccount() {
    int index;
    std::vector<Account> accounts= accountRepository.getAll();
    do {
        std::cout << "\tDostepne hasla : \n";
        for (int i=0 ;i < accounts.size();i++) {
            std::cout << i<<" : " <<accounts.at(i).getName() << std::endl;
        }

        std::cout << "\tpodaj nr hasla do zmiany : ";
        std::cin >> index;
        if(index<0 ||index>=accounts.size())
            std::cout << "wybrano zla wartosc \n";
    }while(index<0 ||index>=accounts.size());
    int nrToChange;
    Account toUpdate = accounts.at(index);
    do {
        std::cout << toUpdate.toString() << "\n";
        std::cout << "wybierz 0 jesli nie chcesz juz nic zmienic \n";
        std::cout << "wybierz 1 jesli chcesz zmienic haslo \n";
        std::cout << "wybierz 2 jesli chcesz zmienic kategorie \n";
        std::cout << "wybierz 3 jesli chcesz zmienic login \n";
        std::cout << "wybierz 4 jesli chcesz zmienic strone \n";
        std::cin>> nrToChange ;
        switch (nrToChange) {
            case 1:{
                std::string pass;
                std::cout <<"podaj nowa wartosc hasla : ";
                std::cin>> pass;
                toUpdate.setPassword(pass);
                std::cout<<"\thaslo zmieniono na "<< pass << '\n';
                break;

            }
            case 2: {
                int catNr;
                std::vector<std::string> categories =categoryRepository.getAll() ;
                do {
//                    for (std::string c:categories ) {
//                        std::cout << c << std::endl;
//                    }
                        for(int i=0;i<categories.size();i++){
                            std::cout<<i <<" "<< categories.at(i) << std::endl;
                        }
                    std::cout << "wybierz nr kategori : ";

                    std::cin >> catNr;
                    if(catNr<0 || catNr> categories.size())
                        std::cout<< "wybrano zla wartosc\n";
                }while(catNr<0 || catNr> categories.size());
                toUpdate.setCategory(categories.at(catNr));
                std::cout<<"\tcategorie zmieniono na "<< categories.at(catNr) << '\n';
                break;
            }
            case 3:{
                std::string login;
                std::cout <<"podaj nowa wartosc loginu : ";
                std::cin>> login;
                toUpdate.setLogin(login);
                std::cout<<"\tlogin zmieniono na "<< login << '\n';
                break;
            }
            case 4:{
                std::string page;
                std::cout <<"podaj nowa wartosc strone : ";
                std::cin>> page;
                toUpdate.setPage(page);
                std::cout<<"\tstrone zmieniono na "<< page << '\n';
                break;

            }

        }
    }while(nrToChange!=0);
    accountRepository.update(toUpdate);

}

void Service::deleteAccount() {

    std::vector<Account> accounts = accountRepository.getAll();
    std::cout << "\t Usuwanie hasla\n";
    if(accounts.empty()){
        std::cout<<"nie ma zadnego hasla !\n";
        return;
    }

    for(int i =0 ; i<accounts.size();i++){
        std::cout<<i<< " : "<< accounts.at(i).getName()<< std::endl;
    }
    int nrToDel;
    do{
        std::cout<< " podaj numer hasla do usuniecia: (jesli jednak nie chcesz nic usuwac wcisnij -1) : ";
        std::cin>> nrToDel;
        if(nrToDel==-1) return;
        if(nrToDel<0 || nrToDel>=accounts.size())
            std::cout << "\nwprowadzona zla wartosc !\n";
    }while(nrToDel<0 || nrToDel>=accounts.size());
    int dec;
    std::cout<<accounts.at(nrToDel).toString()<< std::endl;
    std::cout << "\t czy napewno chcesz usunac to haslo :(wybierz 0 jesli nie ,1 jesli tak)\n: ";

    std::cin >> dec;
    if(dec== 0) return;
    accountRepository.deleteAccount(accounts.at(nrToDel));

}

void Service::showAll() {
    std::vector<Account> accounts = accountRepository.getAll();
    if(accounts.empty())
        std::cout << "nie ma zadnego jeszcze konta \n";
    for(Account a : accounts){
        std::cout<<"\t Haslo :\n";
        std::cout<< a.toString();
    }

}

void Service::deleteCategory() {
    //wybor
    std::cout<<"\t\tusuwanie kategori\n";
    std::vector<std::string> allCat= categoryRepository.getAll();
    for(int i =0; i<allCat.size();i++){
        std::cout<<i<< " : " << allCat.at(i) << std::endl;
    }
    int dec;
    do{
        std::cout<<"wybierz kategorie do usuniecia : ";
        std::cin>>dec;
        if(dec<0 || dec >= allCat.size())
            std::cout<< "\n wprowadzono zla wartosc !\n";
    }while(dec<0 || dec >= allCat.size());
    std::string toDelete = allCat.at(dec);
    categoryRepository.deleteCategory(toDelete);
    std::cout<< "kategoria "<< toDelete <<" usunięta \n";


    std::vector<Account> allAcc = accountRepository.getAll();
    //deletes acc that used  this category;
    for(int i = 0; i <allAcc.size();i++){
        if(allAcc.at(i).getCategory() == toDelete ){
           accountRepository.deleteAccount(allAcc.at(i));
        }
    }
}

void Service::getAccountBy() {
    std::string param;
    std::cout<<"podaj parametr : ";
    std::cin >> param;
    std::vector<Account> found = accountRepository.getBy(param);
    if(found.empty())
        std::cout<< "\n nie znaleziono \n";
    for(Account a : found)
        std::cout << a.toString() << std::endl;

}

void Service::getSortedAcc() {
    std::vector<Account> allAcc = accountRepository.getAll();
    sort(allAcc.begin(),allAcc.end() , [](const Account &l ,const Account &r)->bool {
        if(l.getName()>r.getName() && l.getCategory()>r.getCategory()) return false;
        if(l.getName()>r.getName()) return false;
        return true;
    });
    for(Account a : allAcc){
        std::cout<< a.toString() << std::endl;
    }

}

