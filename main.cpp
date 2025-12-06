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


int main(int argc, char* argv[]) {
    std::string code;

    if (argc > 1) {
        try {
            File file;
            code = file.readFile(argv[1]);
            std::cout << "=== Interpretador Python em C++ ===" << std::endl;
            std::cout << "Arquivo: " << argv[1] << std::endl << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erro ao ler arquivo: " << e.what() << std::endl;
            return 1;
        }
    }else {
        std::cout << "File not found" << std::endl;
        return 0;
    }

    try {
        Lexer lexer(code);
        std::vector<Token> tokens = lexer.tokenize();

        Parser parser(tokens);
        std::vector<std::shared_ptr<ASTNode>> ast = parser.parse();

        Interpreter interpreter;
        std::string output = interpreter.execute(ast);

        std::cout << output << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}