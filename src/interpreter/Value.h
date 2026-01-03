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


#ifndef VALUE_H
#define VALUE_H

#include <string>


class Value {
public:
    enum Type { NUMBER, STRING, BOOLEAN };

    Type type;
    double numValue;
    std::string strValue;
    bool boolValue;

    Value() : type(NUMBER), numValue(0), strValue(""), boolValue(false) {
    }

    Value(double v) : type(NUMBER), numValue(v), strValue(""), boolValue(false) {
    }

    Value(const std::string &v) : type(STRING), numValue(0), strValue(v), boolValue(false) {
    }

    Value(bool v) : type(BOOLEAN), numValue(0), strValue(""), boolValue(v) {
    }

    Value(const Value &other)
        : type(other.type), numValue(other.numValue),
          strValue(other.strValue), boolValue(other.boolValue) {
    }

    Value &operator=(const Value &other) {
        if (this != &other) {
            type = other.type;
            numValue = other.numValue;
            strValue = other.strValue;
            boolValue = other.boolValue;
        }
        return *this;
    }

    std::string toString() const {
        if (type == NUMBER) {
            if (numValue == static_cast<int>(numValue)) {
                return std::to_string(static_cast<int>(numValue));
            }
            return std::to_string(numValue);
        }
        if (type == STRING) return strValue;
        return boolValue ? "True" : "False";
    }

    double toNumber() const {
        if (type == NUMBER) return numValue;
        if (type == BOOLEAN) return boolValue ? 1.0 : 0.0;
        return 0.0;
    }

    bool toBool() const {
        if (type == BOOLEAN) return boolValue;
        if (type == NUMBER) return numValue != 0.0;
        return !strValue.empty();
    }
};


#endif //VALUE_H
