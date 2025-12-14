#ifndef RANGENODE_H
#define RANGENODE_H



class RangeNode : public ASTNode {
public:
    std::shared_ptr<ASTNode> end;
    RangeNode(std::shared_ptr<ASTNode> e) : end(e) {}
};



#endif //RANGENODE_H
