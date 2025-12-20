cmake_minimum_required(VERSION 3.31)
project(python_interpreter)

set(CMAKE_CXX_STANDARD 20)

add_executable(python_interpreter main.cpp
        interpreter/Token.h
        interpreter/Lexer.cpp
        interpreter/Lexer.h
        interpreter/Node/ASTNode.h
        interpreter/Node/NumberNode.h
        interpreter/Node/StringNode.h
        interpreter/Node/VariableNode.h
        interpreter/Node/BinaryOpNode.h
        interpreter/Node/AssignNode.h
        interpreter/Node/PrintNode.h
        interpreter/Node/IfNode.h
        interpreter/Node/ForNode.h
        interpreter/Node/RangeNode.h
        interpreter/Parser.cpp
        interpreter/Parser.h
        interpreter/Value.h
        interpreter/Interpreter.cpp
        interpreter/Interpreter.h
        interpreter/File.cpp
        interpreter/File.h)
