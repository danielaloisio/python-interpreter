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


#include "Interpreter.h"

#include "Node/NumberNode.h"
#include "Node/StringNode.h"
#include "Node/VariableNode.h"
#include "Node/BinaryOpNode.h"
#include "Token.h"
#include "Node/AssignNode.h"
#include "Node/PrintNode.h"
#include "Node/IfNode.h"
#include "Node/ForNode.h"
#include "Node/RangeNode.h"

#include <stdexcept>

Value Interpreter::executeNode(std::shared_ptr<ASTNode> node) {
    if (auto num = dynamic_pointer_cast<NumberNode>(node)) {
        return Value(num->value);
    }

    if (auto str = dynamic_pointer_cast<StringNode>(node)) {
        return Value(str->value);
    }

    if (auto var = dynamic_pointer_cast<VariableNode>(node)) {
        auto it = variables.find(var->name);
        if (it == variables.end()) {
            throw std::runtime_error("Variable '" + var->name + "' not defined");
        }
        return it->second;
    }

    if (auto binOp = dynamic_pointer_cast<BinaryOpNode>(node)) {
        Value left = executeNode(binOp->left);
        Value right = executeNode(binOp->right);

        double l = left.toNumber();
        double r = right.toNumber();

        switch (binOp->op) {
            case TokenType::PLUS: return Value(l + r);
            case TokenType::MINUS: return Value(l - r);
            case TokenType::MULTIPLY: return Value(l * r);
            case TokenType::DIVIDE: return Value(l / r);
            case TokenType::GREATER: return Value(l > r);
            case TokenType::LESS: return Value(l < r);
            case TokenType::EQUALS: return Value(abs(l - r) < 0.0001);
            default: throw std::runtime_error("Unknown operator");
        }
    }

    if (auto assign = dynamic_pointer_cast<AssignNode>(node)) {
        Value val = executeNode(assign->value);
        auto it = variables.find(assign->varName);
        if (it != variables.end()) {
            it->second = val;
        } else {
            variables.insert(std::pair<std::string, Value>(assign->varName, val));
        }
        return val;
    }

    if (auto print = dynamic_pointer_cast<PrintNode>(node)) {
        std::vector<std::string> values;
        for (const auto &arg: print->arguments) {
            Value val = executeNode(arg);
            values.push_back(val.toString());
        }
        std::string result;
        for (size_t i = 0; i < values.size(); i++) {
            result += values[i];
            if (i < values.size() - 1) result += " ";
        }
        output.push_back(result);
        return Value(0.0);
    }

    if (auto ifNode = dynamic_pointer_cast<IfNode>(node)) {
        Value cond = executeNode(ifNode->condition);

        if (cond.toBool()) {
            for (const auto &stmt: ifNode->thenBlock)
                executeNode(stmt);
        } else {
            for (const auto &stmt: ifNode->elseBlock)
                executeNode(stmt);
        }
        return Value(0.0);
    }

    if (auto forNode = dynamic_pointer_cast<ForNode>(node)) {
        if (auto range = dynamic_pointer_cast<RangeNode>(forNode->iterable)) {
            Value endVal = executeNode(range->end);
            int end = static_cast<int>(endVal.toNumber());

            for (int i = 0; i < end; i++) {
                variables[forNode->varName] = Value(static_cast<double>(i));
                for (const auto &stmt: forNode->body)
                    executeNode(stmt);
            }
        }
        return Value(0.0);
    }

    throw std::runtime_error("Unknown node type");
}

std::string Interpreter::execute(const std::vector<std::shared_ptr<ASTNode> > &ast) {
    output.clear();

    try {
        for (const auto &node: ast) {
            executeNode(node);
        }
    } catch (const std::exception &e) {
        return std::string("Execution error: ") + e.what();
    }

    std::string result;
    for (size_t i = 0; i < output.size(); i++) {
        result += output[i];
        if (i < output.size() - 1) {
            result += "\n";
        }
    }
    return result;
}
