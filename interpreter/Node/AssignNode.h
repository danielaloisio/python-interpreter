//
// Created by Daniel Aloísio on 06/12/25.
//

#ifndef ASSIGNNODE_H
#define ASSIGNNODE_H



class AssignNode : public ASTNode {
public:
    std::string varName;
    std::shared_ptr<ASTNode> value;

    AssignNode(const std::string& name, std::shared_ptr<ASTNode> val)
        : varName(name), value(val) {}
};



#endif //ASSIGNNODE_H
