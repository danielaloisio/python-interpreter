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
