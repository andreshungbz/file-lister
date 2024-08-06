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

void listFiles(const std::filesystem::path& directory) {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
        if (std::filesystem::is_regular_file(entry)) {
            std::cout << entry.path().filename().string() << '\n';
        }
    }
}

int main() {
    listFiles(getDirectory());
    return 0;
}
