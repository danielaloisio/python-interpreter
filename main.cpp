/*
Copyright (C) 2025 M3t4l

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see
<https://www.gnu.org/licenses/>.
*/


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "interpreter/Token.h"
#include "interpreter/Lexer.h"
#include "interpreter/Node/ASTNode.h"
#include "interpreter/Parser.h"
#include "interpreter/Interpreter.h"
#include "interpreter/File.h"


int main(int argc, char *argv[]) {
    std::string code;

    if (argc > 1) {
        try {
            File file;
            code = file.readFile(argv[1]);
            std::cout << "*** Python interpreter in C++ ***" << std::endl;
            std::cout << "File: " << argv[1] << std::endl << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Error reading file: " << e.what() << std::endl;
            return 1;
        }
    } else {
        std::cout << "A .py file was not found." << std::endl;
        return 0;
    }

    try {
        Lexer lexer(code);
        std::vector<Token> tokens = lexer.tokenize();

        Parser parser(tokens);
        std::vector<std::shared_ptr<ASTNode> > ast = parser.parse();

        Interpreter interpreter;
        std::string output = interpreter.execute(ast);

        std::cout << output << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
