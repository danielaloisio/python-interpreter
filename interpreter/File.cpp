//
// Created by Daniel Aloísio on 06/12/25.
//

#include <string>
#include <fstream>
#include <sstream>

#include "File.h"


std::string File::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir o arquivo: " + filename);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}
