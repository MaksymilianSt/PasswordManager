

#include "CategoryRepository.h"
/**
 *
 * @return vector of all saved categories from the file
 */
std::vector<std::string> CategoryRepository::getAll() const {
    std::vector<std::string> v;
    std::ifstream File(repoSource);
    if (File.is_open()) {
        std::string line;
        while (std::getline(File, line)) {
            if (!line.empty()){
                v.push_back(line);
            }
        }
        File.close();
    }
    return v;
}
/**
 *
 * @param toSave category to be saved in the list of all categories
 */
void CategoryRepository::saveCategory(const std::string &toSave) const {
    if (findByName(toSave)) return;

    std::ofstream File(repoSource, std::ios::app);
    if (File.is_open()) {
        File << toSave << "\n";
        File.close();
    }

}
/**
 *
 * @param name - name of category to be found
 * @return true if category exist in the list of categories  or false if it doesnt
 */
bool CategoryRepository::findByName(const std::string &name) const {
    std::vector<std::string> categories = getAll();
    bool exist = false;
    for (int i = 0; i < categories.size(); i++) {
        if (categories.at(i) == name) exist = true;
    }
    return exist;
}
/**
 *  function deletes category from the list of all categories
 * @param toDelete -name of category to be deleted
 */
void CategoryRepository::deleteCategory(const std::string &toDelete) {
    std::vector<std::string> listOfCategories = getAll();
    for (int i = 0; i < listOfCategories.size(); i++) {
        if (listOfCategories.at(i) == toDelete) {
            listOfCategories.at(i) = "";
        }
    }

    std::ofstream ListFile(repoSource);
    if (ListFile.is_open()) {
        for (std::string c: listOfCategories) {
            ListFile << c << "\n";
        }
        ListFile.close();

    }

}
