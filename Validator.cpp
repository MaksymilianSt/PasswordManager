//
// Created by Maximiliano on 15.12.2022.
//

#include "Validator.h"

bool Validator::validatePassword(const std::string &toCheck) const {
    int greatNum =0;
    int special =0;
    for(int i =0;i<toCheck.size();i++){
        if(toCheck.at(i)>='A' && toCheck.at(i) <='Z')
            greatNum++;
        if(toCheck.at(i)>=33 && toCheck.at(i) <'A')
            special++;
    }
    return greatNum > 0 && special > 0 && toCheck.size() >=  8;
}

std::string Validator::generatePassword(int size, bool great, bool special) {
    std::string password = "";
    int min,max;
    if(great && special){
        min = 33;
        max =122;
    }else if(great){
        min =65;
        max =122;
    }
    else if(special){
        min =33;
        max =65;
    }
    for(int i = 0 ; i<= size; i++ ){
        if(!great && special){
            char sign =rand() % 122+ 34 ;
            while(sign>= 'A' && sign <= 'Z'){
                sign =rand() % 122+ 34 ;
            }
            password+= sign;
        }
        password += (char)( rand() % max-min +min);
    }
    return password;
}
