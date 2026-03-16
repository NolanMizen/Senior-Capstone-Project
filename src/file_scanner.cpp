#include "file_scanner.h"
#include <filesystem>

namespace fs = std::filesystem;

// helper function that checks the file extension, if it matches one of these then it will pass CPP, PYTHON, JAVASCRIPT, or UNKNOWN
static Language detectLanguage(const std::string& extension) {
    if (extension == ".cpp" || extension == ".cc" || extension == ".cxx" || extension == ".hpp" || extension == ".h") {
        return Language::CPP;
    }
    if (extension == ".py") {
        return Language::PYTHON;
    }
    if (extension == ".js") {
        return Language::JAVASCRIPT;
    }
    return Language::UNKNOWN;
}

std::vector<SourceFile> scanDirectory(const std::string& path) {
    std::vector<SourceFile> files;

    // this bit of code here scans a directory (sample_code) that is put into our Makefile and detects if these files exist
    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();
            Language language = detectLanguage(extension);

            if (language != Language::UNKNOWN) {
                SourceFile file;
                file.path = entry.path().string();
                file.extension = extension;
                file.language = language;
                files.push_back(file);
            }
        
        }
    }

    return files;
}

std::string languageToString(Language language) {
    switch (language) {
        case Language::CPP:
            return "C++";
        case Language::PYTHON:
            return "Python";
        case Language::JAVASCRIPT:
            return "Javascript";
        default:
            return "Unknown";
    }
}
