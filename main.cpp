#include <filesystem>
#include <iostream>

std::filesystem::path getDirectory() {
    std::string path;
    while (true) {
        std::cout << "Enter directory path: ";
        std::getline(std::cin >> std::ws, path);

        try {
            std::filesystem::path fsPath{path};

            if (std::filesystem::exists(fsPath) && std::filesystem::is_directory(fsPath)) {
                return fsPath;
            } else {
                std::cout << "Invalid directory. Try again.\n";
            }
        } catch (const std::filesystem::filesystem_error& error) {
            std::cout << "File System Error: " << error.what() << '\n';
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
