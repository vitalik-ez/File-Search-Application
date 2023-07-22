#ifndef SEARCH_LIB_H
#define SEARCH_LIB_H

#include <string>
#include <vector>

class SearchLibrary {
public:
    static void searchFile(const std::string& rootDir, const std::string& fileName, bool& found);
};

#endif // SEARCH_LIB_H
