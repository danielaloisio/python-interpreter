#ifndef NUMBERNODE_H
#define NUMBERNODE_H



class NumberNode : public ASTNode {
public:
    double value;
    NumberNode(double v) : value(v) {}
};


#endif //NUMBERNODE_H
