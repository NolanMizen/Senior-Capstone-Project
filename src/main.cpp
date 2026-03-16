#include <iostream>
#include <string>
#include <vector>
#include "file_scanner.h"

int main(int argc, char* argv[]) {
    // grab our command arguments when we run our program ./ccc
    if (argc < 2) {
        std::cout << "Usage: ./ccc <directory>\n";
        return 1;
    }

    // use our directory we are scanning as our 
    std::string path = argv[1];

    std::cout << "Scanning directory: " << path << "\n\n";

    // scan our directory with the function from file_scanner.h and store them in our vector
    std::vector<SourceFile> files = scanDirectory(path);

    // if there aren't any files, then we send a message and return
    if (files.empty()) {
        std::cout << "No supported source files found.\n";
        return 0;
    }

    // output our vector of strings with all of the filetypes that our program found
    std::cout << "Found files:\n";
    for (const auto& file : files) {
        std::cout << "[" << languageToString(file.language) << "]" << file.path << " (" << file.extension << ")\n";
    }

    return 0;
}
