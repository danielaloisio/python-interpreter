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


#ifndef PARSER_H
#define PARSER_H
#include <memory>
#include <vector>
#include "Token.h"
#include "Node/ASTNode.h"


class Parser {
private:
    std::vector<Token> tokens;
    size_t position;

    Token &currentToken();

    void advance();

    void expect(TokenType type);

    void skipNewlines();

    std::shared_ptr<ASTNode> parsePrimary();

    std::shared_ptr<ASTNode> parseFactor();

    std::shared_ptr<ASTNode> parseTerm();

    std::shared_ptr<ASTNode> parseComparison();

    std::shared_ptr<ASTNode> parseExpression();

    std::shared_ptr<ASTNode> parsePrint();

    std::shared_ptr<ASTNode> parseIf();

    std::shared_ptr<ASTNode> parseFor();

    std::shared_ptr<ASTNode> parseStatement();

public:
    Parser(const std::vector<Token> &toks) : tokens(toks), position(0) {
    }

    std::vector<std::shared_ptr<ASTNode> > parse();
};


#endif //PARSER_H
