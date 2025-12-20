#include <string>

#include "Parser.h"
#include "Node/AssignNode.h"
#include "Node/BinaryOpNode.h"
#include "Node/ForNode.h"
#include "Node/IfNode.h"
#include "Node/NumberNode.h"
#include "Node/PrintNode.h"
#include "Node/RangeNode.h"
#include "Node/StringNode.h"
#include "Node/VariableNode.h"

#include <stdexcept>

Token &Parser::currentToken() {
    return tokens[position < tokens.size() ? position : tokens.size() - 1];
}

void Parser::advance() {
    if (position < tokens.size()) position++;
}

void Parser::expect(TokenType type) {
    if (currentToken().type != type) {
        throw std::runtime_error("Expected token type " + std::to_string(static_cast<int>(type)) +
                                 " on the line " + std::to_string(currentToken().line));
    }
    advance();
}

void Parser::skipNewlines() {
    while (currentToken().type == TokenType::NEWLINE)
        advance();
}

std::shared_ptr<ASTNode> Parser::parsePrimary() {
    if (currentToken().type == TokenType::NUMBER) {
        double value = stod(currentToken().value);
        advance();
        return std::make_shared<NumberNode>(value);
    }

    if (currentToken().type == TokenType::STRING) {
        std::string value = currentToken().value;
        advance();
        return make_shared<StringNode>(value);
    }

    if (currentToken().type == TokenType::IDENTIFIER) {
        std::string name = currentToken().value;
        advance();
        return std::make_shared<VariableNode>(name);
    }

    if (currentToken().type == TokenType::KEYWORD && currentToken().value == "range") {
        advance();
        expect(TokenType::LPAREN);
        auto end = parseExpression();
        expect(TokenType::RPAREN);
        return std::make_shared<RangeNode>(end);
    }

    if (currentToken().type == TokenType::LPAREN) {
        advance();
        auto expr = parseExpression();
        expect(TokenType::RPAREN);
        return expr;
    }

    throw std::runtime_error("Unexpected token on line " + std::to_string(currentToken().line));
}

std::shared_ptr<ASTNode> Parser::parseFactor() {
    auto left = parsePrimary();

    while (currentToken().type == TokenType::MULTIPLY || currentToken().type == TokenType::DIVIDE) {
        TokenType op = currentToken().type;
        advance();
        auto right = parsePrimary();
        left = make_shared<BinaryOpNode>(left, op, right);
    }

    return left;
}

std::shared_ptr<ASTNode> Parser::parseTerm() {
    auto left = parseFactor();

    while (currentToken().type == TokenType::PLUS || currentToken().type == TokenType::MINUS) {
        TokenType op = currentToken().type;
        advance();
        auto right = parseFactor();
        left = make_shared<BinaryOpNode>(left, op, right);
    }

    return left;
}

std::shared_ptr<ASTNode> Parser::parseComparison() {
    auto left = parseTerm();

    while (currentToken().type == TokenType::GREATER ||
           currentToken().type == TokenType::LESS ||
           currentToken().type == TokenType::EQUALS) {
        TokenType op = currentToken().type;
        advance();
        auto right = parseTerm();
        left = make_shared<BinaryOpNode>(left, op, right);
    }

    return left;
}

std::shared_ptr<ASTNode> Parser::parseExpression() {
    return parseComparison();
}

std::shared_ptr<ASTNode> Parser::parsePrint() {
    expect(TokenType::KEYWORD);
    expect(TokenType::LPAREN);

    std::vector<std::shared_ptr<ASTNode> > args;

    if (currentToken().type != TokenType::RPAREN) {
        args.push_back(parseExpression());

        while (currentToken().type == TokenType::COMMA) {
            advance();
            args.push_back(parseExpression());
        }
    }

    expect(TokenType::RPAREN);
    return make_shared<PrintNode>(args);
}

std::shared_ptr<ASTNode> Parser::parseIf() {
    expect(TokenType::KEYWORD);
    auto condition = parseExpression();
    expect(TokenType::COLON);
    expect(TokenType::NEWLINE);
    expect(TokenType::INDENT);

    std::vector<std::shared_ptr<ASTNode> > thenBlock;
    while (currentToken().type != TokenType::DEDENT && currentToken().type != TokenType::END_OF_FILE) {
        thenBlock.push_back(parseStatement());
        skipNewlines();
    }

    if (currentToken().type == TokenType::DEDENT)
        advance();

    std::vector<std::shared_ptr<ASTNode> > elseBlock;
    if (currentToken().type == TokenType::KEYWORD && currentToken().value == "else") {
        advance();
        expect(TokenType::COLON);
        expect(TokenType::NEWLINE);
        expect(TokenType::INDENT);

        while (currentToken().type != TokenType::DEDENT && currentToken().type != TokenType::END_OF_FILE) {
            elseBlock.push_back(parseStatement());
            skipNewlines();
        }

        if (currentToken().type == TokenType::DEDENT)
            advance();
    }

    return make_shared<IfNode>(condition, thenBlock, elseBlock);
}

std::shared_ptr<ASTNode> Parser::parseFor() {
    expect(TokenType::KEYWORD);
    std::string varName = currentToken().value;
    expect(TokenType::IDENTIFIER);
    expect(TokenType::KEYWORD);

    auto iterable = parseExpression();
    expect(TokenType::COLON);
    expect(TokenType::NEWLINE);
    expect(TokenType::INDENT);

    std::vector<std::shared_ptr<ASTNode> > body;
    while (currentToken().type != TokenType::DEDENT && currentToken().type != TokenType::END_OF_FILE) {
        body.push_back(parseStatement());
        skipNewlines();
    }

    if (currentToken().type == TokenType::DEDENT)
        advance();

    return make_shared<ForNode>(varName, iterable, body);
}

std::shared_ptr<ASTNode> Parser::parseStatement() {
    if (currentToken().type == TokenType::KEYWORD) {
        if (currentToken().value == "print") return parsePrint();
        if (currentToken().value == "if") return parseIf();
        if (currentToken().value == "for") return parseFor();
    }

    if (currentToken().type == TokenType::IDENTIFIER) {
        std::string varName = currentToken().value;
        advance();

        if (currentToken().type == TokenType::ASSIGN) {
            advance();
            auto value = parseExpression();
            return make_shared<AssignNode>(varName, value);
        }
    }

    throw std::runtime_error("Invalid statement on line " + std::to_string(currentToken().line));
}

std::vector<std::shared_ptr<ASTNode> > Parser::parse() {
    std::vector<std::shared_ptr<ASTNode> > statements;
    skipNewlines();

    while (currentToken().type != TokenType::END_OF_FILE) {
        statements.push_back(parseStatement());
        skipNewlines();
    }

    return statements;
}
