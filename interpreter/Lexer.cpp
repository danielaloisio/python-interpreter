#include "Lexer.h"

#include <stdexcept>

bool Lexer::isKeyword(const std::string& word) {
    for (const auto& kw : keywords) {
        if (kw == word) return true;
    }
    return false;
}

Token Lexer::readNumber() {
    std:: string number;
    int startLine = line;

    while (position < code.length() && (isdigit(code[position]) || code[position] == '.')) {
        number += code[position];
        position++;
    }

    return Token(TokenType::NUMBER, number, startLine);
}

Token Lexer::readString(char quote) {
    std::string str;
    int startLine = line;
    position++;

    while (position < code.length() && code[position] != quote) {
        str += code[position];
        position++;
    }

    position++;
    return Token(TokenType::STRING, str, startLine);
}

Token Lexer::readIdentifier() {
    std::string identifier;
    int startLine = line;

    while (position < code.length() && (isalnum(code[position]) || code[position] == '_')) {
        identifier += code[position];
        position++;
    }

    TokenType type = isKeyword(identifier) ? TokenType::KEYWORD : TokenType::IDENTIFIER;
    return Token(type, identifier, startLine);
}

 std::vector<Token> Lexer::tokenize() {
        std::vector<Token> tokens;
        std::vector<int> indentStack = {0};

        while (position < code.length()) {
            char current = code[position];

            if (current == ' ' || current == '\t') {
                position++;
                continue;
            }

            if (current == '\n') {
                tokens.push_back(Token(TokenType::NEWLINE, "\\n", line));
                position++;
                line++;

                int indent = 0;
                while (position < code.length() && (code[position] == ' ' || code[position] == '\t')) {
                    indent += (code[position] == ' ') ? 1 : 4;
                    position++;
                }

                if (position < code.length() && code[position] != '\n' && code[position] != '#') {
                    if (indent > indentStack.back()) {
                        tokens.push_back(Token(TokenType::INDENT, "", line));
                        indentStack.push_back(indent);
                    } else if (indent < indentStack.back()) {
                        while (!indentStack.empty() && indent < indentStack.back()) {
                            tokens.push_back(Token(TokenType::DEDENT, "", line));
                            indentStack.pop_back();
                        }
                    }
                }
                continue;
            }

            if (current == '#') {
                while (position < code.length() && code[position] != '\n')
                    position++;
                continue;
            }

            if (isdigit(current)) {
                tokens.push_back(readNumber());
                continue;
            }

            if (current == '"' || current == '\'') {
                tokens.push_back(readString(current));
                continue;
            }

            if (isalpha(current) || current == '_') {
                tokens.push_back(readIdentifier());
                continue;
            }

            switch (current) {
                case '+': tokens.push_back(Token(TokenType::PLUS, "+", line)); position++; break;
                case '-': tokens.push_back(Token(TokenType::MINUS, "-", line)); position++; break;
                case '*': tokens.push_back(Token(TokenType::MULTIPLY, "*", line)); position++; break;
                case '/': tokens.push_back(Token(TokenType::DIVIDE, "/", line)); position++; break;
                case '(': tokens.push_back(Token(TokenType::LPAREN, "(", line)); position++; break;
                case ')': tokens.push_back(Token(TokenType::RPAREN, ")", line)); position++; break;
                case ',': tokens.push_back(Token(TokenType::COMMA, ",", line)); position++; break;
                case ':': tokens.push_back(Token(TokenType::COLON, ":", line)); position++; break;
                case '=':
                    if (position + 1 < code.length() && code[position + 1] == '=') {
                        tokens.push_back(Token(TokenType::EQUALS, "==", line));
                        position += 2;
                    } else {
                        tokens.push_back(Token(TokenType::ASSIGN, "=", line));
                        position++;
                    }
                    break;
                case '>': tokens.push_back(Token(TokenType::GREATER, ">", line)); position++; break;
                case '<': tokens.push_back(Token(TokenType::LESS, "<", line)); position++; break;
                default:
                    throw std::runtime_error("Unexpected character: " + std::string(1, current) + " one the line " + std::to_string(line));
            }
        }

        while (indentStack.size() > 1) {
            tokens.push_back(Token(TokenType::DEDENT, "", line));
            indentStack.pop_back();
        }

        tokens.push_back(Token(TokenType::END_OF_FILE, "", line));
        return tokens;
    }
