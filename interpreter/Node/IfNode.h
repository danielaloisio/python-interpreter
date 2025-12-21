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


#ifndef IFNODE_H
#define IFNODE_H


class IfNode : public ASTNode {
public:
    std::shared_ptr<ASTNode> condition;
    std::vector<std::shared_ptr<ASTNode> > thenBlock;
    std::vector<std::shared_ptr<ASTNode> > elseBlock;

    IfNode(std::shared_ptr<ASTNode> cond,
           const std::vector<std::shared_ptr<ASTNode> > &thenB,
           const std::vector<std::shared_ptr<ASTNode> > &elseB = {})
        : condition(cond), thenBlock(thenB), elseBlock(elseB) {
    }
};


#endif //IFNODE_H
