//
// Created by Daniel Aloísio on 06/12/25.
//

#ifndef STRINGNODE_H
#define STRINGNODE_H



class StringNode : public ASTNode {
public:
    std::string value;
    StringNode(const std::string& v) : value(v) {}
};


#endif //STRINGNODE_H
