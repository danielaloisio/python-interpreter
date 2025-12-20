#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <map>
#include <memory>
#include <vector>
#include "Value.h"
#include "Node/ASTNode.h"

class Interpreter {
private:
    std::map<std::string, Value> variables;
    std::vector<std::string> output;

    Value executeNode(std::shared_ptr<ASTNode> node);

public:
    std::string execute(const std::vector<std::shared_ptr<ASTNode> > &ast);
};


#endif //INTERPRETER_H
