#include "search_lib.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <root_directory> <filename>" << std::endl;
        return 1;
    }

    std::string rootDir = argv[1];
    std::string fileName = argv[2];

    bool found = false;
    SearchLibrary::searchFile(rootDir, fileName, found);

    if (!found) {
        std::cout << "File not found." << std::endl;
    }

    return 0;
}
