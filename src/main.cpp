#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int, argc, char* argv[]) {

    if (argc > 2) {
        std::cout << "Usage: ./ccc <directory>\n";
        return 1;
    }

    std::string path = argv[1];

    std::cout << "Scanning Directory: " << path << "\n\n";

    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();

            if (extension == ".cpp" || extension == ".py" || extension == ".js" || )
                std::cout << entry.path() << std::endl;
        }
    }

    return 0;
}