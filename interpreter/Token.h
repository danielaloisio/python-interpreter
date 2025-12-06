//
// Created by Daniel Aloísio on 06/12/25.
//

#ifndef TOKEN_H
#define TOKEN_H

enum class TokenType {
    NUMBER, STRING, IDENTIFIER, KEYWORD,
    PLUS, MINUS, MULTIPLY, DIVIDE,
    ASSIGN, EQUALS, GREATER, LESS,
    LPAREN, RPAREN, COMMA, COLON,
    NEWLINE, INDENT, DEDENT, END_OF_FILE
};

class Token {
public:
    TokenType type;
    std::string value;
    int line;

    Token(TokenType t, const std::string& v, int l) : type(t), value(v), line(l) {}

    std::string toString() const {
        return "Token(" + std::to_string(static_cast<int>(type)) + ", " + value + ", Line " + std::to_string(line) + ")";
    }
};


#endif //TOKEN_H
