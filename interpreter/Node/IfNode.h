//
// Created by Daniel Aloísio on 06/12/25.
//

#ifndef IFNODE_H
#define IFNODE_H



class IfNode : public ASTNode {
public:
    std::shared_ptr<ASTNode> condition;
    std::vector<std::shared_ptr<ASTNode>> thenBlock;
    std::vector<std::shared_ptr<ASTNode>> elseBlock;

    IfNode(std::shared_ptr<ASTNode> cond,
           const std::vector<std::shared_ptr<ASTNode>>& thenB,
           const std::vector<std::shared_ptr<ASTNode>>& elseB = {})
        : condition(cond), thenBlock(thenB), elseBlock(elseB) {}
};



#endif //IFNODE_H
