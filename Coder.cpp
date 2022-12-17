//
// Created by Maximiliano on 14.12.2022.
//

#include "Coder.h"

std::string Coder::deCode(const std::string &toDecode) const{
    if(toDecode.empty()) return "";
    std::string decoded="";
    for(int i=0;i<toDecode.size();i++){
        if(i%4 ==0){
            decoded+=toDecode.at(i);
        }
    }

    return decoded;
}
//TODO:const corr
std::string Coder::code(const std::string &toCode)const {
    if(toCode.empty()) return "";
    std::string coded="";
    for(int i = 0 ; i <toCode.size() ; i ++){
        coded+= toCode.at(i);
        coded+=  rand() % 56 +34;
        coded+=  rand() % 56 +34;
        coded+=  rand() % 56 +34;
    }
    return coded;

}
