# Python-like Interpreter (C++)

Description
-----------
This repository contains a small interpreter written in C++ with a syntax inspired by Python. It is an educational project to learn about lexical analysis (lexer), parsing, AST (abstract syntax tree) nodes, and evaluation/interpretation.

Project layout
--------------
- `interpreter/` - core implementation: `Lexer`, `Parser`, `Interpreter`, AST `Node` definitions, `Token`, `Value`, and `File` utilities.
- `main.cpp` - C++ entry point.

Prerequisites
-------------
- CMake (>= 3.10 recommended)
- A recent C++ compiler (Clang or GCC with C++11/14/17 support)
- (Optional) An IDE such as CLion or VSCode, or build tools like Make/Ninja

How to build (macOS / Linux / Windows (MSYS2))
---------------------------------------------
Open a terminal at the repository root and run:

```bash
mkdir -p build && cd build
cmake ..
cmake --build .
```

Running the interpreter
-----------------------
To run the interpreter without arguments:

```bash
./build/python_interpreter
```

If the binary accepts a script file, run it like this:

```bash
./build/python_interpreter path/to/script.py
```

Example script (example.py)
---------------------------
```
# example.py
x = 0
for i in range(1, 5):
    print(i)

print("End of loop")
```

Expected output (implementation-dependent):
```
1
2
3
4
End of loop
```

Code structure
--------------
- `interpreter/Lexer.*` - tokenization
- `interpreter/Parser.*` - AST construction
- `interpreter/Interpreter.*` - AST execution/evaluation
- `interpreter/Node/` - AST node definitions (AssignNode, ForNode, PrintNode, etc.)
- `interpreter/File.*` - file reading utilities
