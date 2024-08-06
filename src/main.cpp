#include "file-utils.h"
#include <iostream>

int main(int argc, char* argv[]) {
    std::filesystem::path directory;
    bool reprompt{false};

    if (argc > 1) {
        directory = std::filesystem::path(argv[1]);

        if (!std::filesystem::exists(directory) || !std::filesystem::is_directory(directory)) {
            std::cout << "Invalid directory. Try again.\n";
            reprompt = true;
        }
    }

    if (argc == 1 || reprompt) {
        directory = getDirectory();
    }

    listFiles(directory);
    return 0;
}
