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

    bool isKeyword(const std::string &word);

    Token readNumber();

    Token readString(char quote);

    Token readIdentifier();

public:
    Lexer(const std::string &sourceCode) : code(sourceCode), position(0), line(1) {
    }

    std::vector<Token> tokenize();
};


#endif //LEXER_H
