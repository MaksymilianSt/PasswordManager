#include <iostream>
#include <chrono>
#include "CategoryRepository.h"
#include "time.h"
#include "AccountRepository.h"
#include "Coder.h"
#include "Service.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    //Todo: doxy , usuniecie pierdół itp
    Service service ;
int nr;
do{
    std::cout<< "\n\t\t*wybeirz nr *"<<"\n";
    std::cout<<"wybierz 0 jezeli chcesz wyswietlic wszystkie konta"<<std::endl;
    std::cout<<"wybierz 1 jezeli chcesz znalezc konto po parametrze"<<std::endl;
    std::cout<<"wybierz 2 jezeli chcesz posortowane konta"<<std::endl;
    std::cout<<"wybierz 3 jezeli chcesz dodac nowe konto"<<std::endl;
    std::cout<<"wybierz 4 jezeli chcesz edytowac haslo"<<std::endl;
    std::cout<<"wybierz 5 jezeli chcesz usunac haslo"<<std::endl;
    std::cout<<"wybierz 6 jezeli chcesz dodac kategorie"<<std::endl;
    std::cout<<"wybierz 7 jezeli chcesz usunac kategorie"<<std::endl;
    std::cout<<"\tdecyzja : ";

    std::cin >>nr;
    switch (nr) {
        case 0:{
            service.showAll();
            break;
        }
        case 1:{
            service.getAccountBy();
            break;
        }
        case 2:{
            service.getSortedAcc();
            break;
        }
        case 3:{
            service.addAccount();
            break;
        }
        case 4:{
            service.editAccount();
            break;
        }
        case 5:{
            service.deleteAccount();
            break;
        }
        case 6:{
            service.addCategory();
            break;
        }
        case 7:{
            service.deleteCategory();
            break;
        }

    }


}while(nr>0 || nr < 10);//ilosc polecen10


//
//
//
//    CategoryRepository repo ;
//    repo.saveCategory("categoria zmieniona");
//    std::vector<std::string> vec = repo.getAll();
//    for(int i= 0; i < vec.size();i++){
//        std::cout<< vec.at(i) <<"\n";
//    }
//        AccountRepository repos ;
//        Account acc;
//
//        acc.setName("AA");
//        acc.setPassword("JDDD");
//        acc.setCategory("JD JD");
//        acc.setLogin("");
//        acc.setPage("UBUDUBU");
//        repos.save(acc);
//        std::vector<Account> vek= repos.getAll();
//        for(int i =0 ; i< vek.size();i++){
//            std::cout<<"konto: "<< vek[i].getCategory() << std::endl;
//            std::cout<<"login: "<< vek[i].getLogin() << std::endl;
//            std::cout<< "strona: "<<vek[i].getPage() << std::endl;

   //     }
//    std::string sr="";
//    sr += "b";
//    sr += "c";
//    sr += "a";
//    std:: cout << sr << " jd :" << sr.at(2) << '\n' ;
//    std::string  nowy ;
//    std::string  nowy2 ;
//    Coder cot ;
//    nowy = cot.code("L09k87j65");
//    std::cout <<"coded: "<< nowy << "\n";
//    std::cout <<"decoded: "<< cot.deCode(nowy) << "\n";


    return 0;
}
