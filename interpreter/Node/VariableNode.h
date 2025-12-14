#ifndef VARIABLENODE_H
#define VARIABLENODE_H



class VariableNode : public ASTNode {
public:
    std::string name;
    VariableNode(const std::string& n) : name(n) {}
};



#endif //VARIABLENODE_H
