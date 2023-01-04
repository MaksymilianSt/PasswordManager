

#ifndef PROJEKTHASLO_CATEGORYREPOSITORY_H
#define PROJEKTHASLO_CATEGORYREPOSITORY_H


#include <string>
#include <set>
#include "vector"
#include "fstream"

class CategoryRepository {


private:
    static std::set<std::string> categories;
private:
    const std::string repoSource = "categories.txt";
public:
    std::vector<std::string> getAll() const;
public :
    void saveCategory(const std::string &toSave)const;
public:
    bool findByName(const std::string &name)const;
public:
    void deleteCategory(const std::string & toDelete);



};


#endif //PROJEKTHASLO_CATEGORYREPOSITORY_H
