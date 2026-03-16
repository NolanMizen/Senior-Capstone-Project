#include <iostream>
#include <string>
#include <vector>
#include "file_scanner.h"
#include "analyzer.h"

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

    // Where we trigger our parsing stub
    std::cout << "\nBeginning analysis...\n\n";

    // Output our file statistics in a grid
    for (const auto& file : files) {
        AnalysisResult result = analyzeFile(file);

        std::cout << "File: " << result.filePath << "\n";
        std::cout << "Language: " << languageToString(result.language) << "\n";
        std::cout << "Status: " << (result.success ? "Success" : "Failed") << "\n";
        std::cout << "Message: " << result.message << "\n";
        std::cout << "Total Lines: " << result.totalLines << "\n";
        std::cout << "Non-Empty Lines: " << result.nonEmptyLines << "\n\n";
    }

    return 0;
}
