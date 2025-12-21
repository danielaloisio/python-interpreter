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


#ifndef FORNODE_H
#define FORNODE_H


class ForNode : public ASTNode {
public:
    std::string varName;
    std::shared_ptr<ASTNode> iterable;
    std::vector<std::shared_ptr<ASTNode> > body;

    ForNode(const std::string &var, std::shared_ptr<ASTNode> iter, const std::vector<std::shared_ptr<ASTNode> > &b)
        : varName(var), iterable(iter), body(b) {
    }
};


#endif //FORNODE_H
