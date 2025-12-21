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


#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <map>
#include <memory>
#include <vector>
#include "Value.h"
#include "Node/ASTNode.h"

class Interpreter {
private:
    std::map<std::string, Value> variables;
    std::vector<std::string> output;

    Value executeNode(std::shared_ptr<ASTNode> node);

public:
    std::string execute(const std::vector<std::shared_ptr<ASTNode> > &ast);
};


#endif //INTERPRETER_H
