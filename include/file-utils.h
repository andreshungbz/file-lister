#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <filesystem>
#include <string>

// Function declarations
std::filesystem::path getDirectory();
void listFiles(const std::filesystem::path& directory);

#endif // FILE_UTILS_H
