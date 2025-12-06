//
// Created by Daniel Aloísio on 06/12/25.
//

#ifndef FORNODE_H
#define FORNODE_H



class ForNode : public ASTNode {
public:
    std::string varName;
    std::shared_ptr<ASTNode> iterable;
    std::vector<std::shared_ptr<ASTNode>> body;

    ForNode(const std::string& var, std::shared_ptr<ASTNode> iter, const std::vector<std::shared_ptr<ASTNode>>& b)
        : varName(var), iterable(iter), body(b) {}
};


#endif //FORNODE_H
