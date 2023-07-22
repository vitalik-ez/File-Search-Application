#include "search_lib.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];

    bool found = false;
    SearchLibrary::searchFile("/", fileName, found);

    if (!found) {
        std::cout << "File not found." << std::endl;
    }

    return 0;
}
