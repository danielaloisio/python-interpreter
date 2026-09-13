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


#ifndef RANGENODE_H
#define RANGENODE_H


class RangeNode : public ASTNode {
public:
    std::shared_ptr<ASTNode> start;
    std::shared_ptr<ASTNode> end;
    std::shared_ptr<ASTNode> step;

    RangeNode(std::shared_ptr<ASTNode> s, std::shared_ptr<ASTNode> e, std::shared_ptr<ASTNode> st)
        : start(s), end(e), step(st) {
    }
};


#endif //RANGENODE_H
