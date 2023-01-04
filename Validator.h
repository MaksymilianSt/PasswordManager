

#ifndef PROJEKTHASLO_VALIDATOR_H
#define PROJEKTHASLO_VALIDATOR_H


#include <string>

class Validator {
public:
    bool validatePassword(const std::string & toCheck)const;
    std::string generatePassword(int size ,bool great , bool special );

};


#endif //PROJEKTHASLO_VALIDATOR_H
