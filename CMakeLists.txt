cmake_minimum_required(VERSION 3.31)
project(python_interpreter)

set(CMAKE_CXX_STANDARD 20)

add_executable(python_interpreter src/main.cpp
        src/interpreter/Token.h
        src/interpreter/Lexer.cpp
        src/interpreter/Lexer.h
        src/interpreter/Node/ASTNode.h
        src/interpreter/Node/NumberNode.h
        src/interpreter/Node/StringNode.h
        src/interpreter/Node/VariableNode.h
        src/interpreter/Node/BinaryOpNode.h
        src/interpreter/Node/AssignNode.h
        src/interpreter/Node/PrintNode.h
        src/interpreter/Node/IfNode.h
        src/interpreter/Node/ForNode.h
        src/interpreter/Node/RangeNode.h
        src/interpreter/Parser.cpp
        src/interpreter/Parser.h
        src/interpreter/Value.h
        src/interpreter/Interpreter.cpp
        src/interpreter/Interpreter.h
        src/interpreter/File.cpp
        src/interpreter/File.h)
