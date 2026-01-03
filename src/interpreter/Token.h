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

    Token(TokenType t, const std::string &v, int l) : type(t), value(v), line(l) {
    }

    std::string toString() const {
        return "Token(" + std::to_string(static_cast<int>(type)) + ", " + value + ", Line " + std::to_string(line) +
               ")";
    }
};


#endif //TOKEN_H
