//
// Created by Daniel Aloísio on 06/12/25.
//

#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
#include "Token.h"

class Lexer {
private:
    std::string code;
    size_t position;
    int line;
    std::vector<std::string> keywords = {"if", "else", "for", "in", "range", "print", "while", "def", "return"};

    bool isKeyword(const std::string& word);

    Token readNumber();

    Token readString(char quote);

    Token readIdentifier();

public:
    Lexer(const std::string& sourceCode) : code(sourceCode), position(0), line(1) {}

    std::vector<Token> tokenize();
};



#endif //LEXER_H
