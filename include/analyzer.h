#ifndef ANALYZER_H
#define ANALYZER_H

#include <string>
#include "file_scanner.h"

struct AnalysisResult {
    std::string filePath;
    Language language;
    bool success;
    std::string message;

    int totalLines;
    int nonEmptyLines;
};

AnalysisResult analyzeFile(const SourceFile& file);

#endif