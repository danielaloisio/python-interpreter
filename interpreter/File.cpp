#include <string>
#include <fstream>
#include <sstream>

#include "File.h"

std::string File::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("The file could not be opened.: " + filename);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}
