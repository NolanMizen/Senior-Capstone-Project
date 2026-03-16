#ifndef FILE_SCANNER_H
#define FILE_SCANNER_H

#include <string>
#include <vector>

// create the languages we support from our three given code files.
enum class Language {
    CPP,
    PYTHON,
    JAVASCRIPT,
    UNKNOWN
};

// Use a structure to hold our lanugage data, our path, and our extension
struct SourceFile {
    std::string path;
    std::string extension;
    Language language;
};

// the main function that scans our directory for our files
std::vector<SourceFile> scanDirectory(const std::string& path);

std::string languageToString(Language language);


#endif
