#ifndef BINARYOPNODE_H
#define BINARYOPNODE_H

#include "../Token.h"


class BinaryOpNode : public ASTNode {
public:
    std::shared_ptr<ASTNode> left;
    TokenType op;
    std::shared_ptr<ASTNode> right;

    BinaryOpNode(std::shared_ptr<ASTNode> l, TokenType o, std::shared_ptr<ASTNode> r)
        : left(l), op(o), right(r) {
    }
};


#endif //BINARYOPNODE_H
