

#include "Coder.h"
/**
 *
 * @param toDecode string to decode
 * @return decoded string
 */
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
/**
 *
 * @param toCode - string to be coded
 * @return coded string
 */
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
