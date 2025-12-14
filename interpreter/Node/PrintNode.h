#ifndef PRINTNODE_H
#define PRINTNODE_H



class PrintNode : public ASTNode {
public:
    std::vector<std::shared_ptr<ASTNode>> arguments;
    PrintNode(const std::vector<std::shared_ptr<ASTNode>>& args) : arguments(args) {}
};


#endif //PRINTNODE_H
