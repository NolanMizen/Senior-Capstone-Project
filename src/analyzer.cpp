#include "analyzer.h"
#include <fstream>

AnalysisResult analyzeFile(const SourceFile& file) {
    AnalysisResult result;
    result.filePath = file.path;
    result.language = file.language;
    result.success = true;
    result.message = "Basic file analysis completed";
    result.totalLines = 0;
    result.nonEmptyLines = 0;

    // open our input file using fstream and if it doesn't work then trigger
    std::ifstream inputFile(file.path);
    if (!inputFile.is_open()) {
        result.success = false;
        result.message = "Failed to open file";
        return result;
    }

    // count how many lines we have as well as lines that are empty
    std::string line;
    while (std::getline(inputFile, line)) {
        result.totalLines++;

        if (!line.empty()) {
            result.nonEmptyLines++;
        }
    }

    return result;
}