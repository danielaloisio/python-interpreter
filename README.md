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
To run the interpreter on Linux and MacOS:

```bash
cd build
./python_interpreter path/to/script.py
```

To run the interpreter on Windows:     

```bash
cd build
python_interpreter.exe path/to/script.py
```

Supported language features
----------------------------
- Variables, numbers, strings and arithmetic/comparison expressions (`+ - * / > < ==`, unary `-`)
- `print(...)` with multiple comma-separated arguments
- `if` / `else`
- `for x in range(...)`, with the same signatures as Python:
  - `range(end)`
  - `range(start, end)`
  - `range(start, end, step)` (including negative steps, e.g. counting down)
- Functions with `def`, parameters and `return` (including recursion). Functions have their own local scope: assignments inside a function do not leak to the caller.

Example script (example.py)
---------------------------
```python
# example.py
x = 0
for i in range(5):
    print(i)

print("End of loop")

def factorial(n):
    if n < 2:
        return 1
    return n * factorial(n - 1)

print(factorial(5))
```

Expected output (implementation-dependent):
```
0
1
2
3
4
End of loop
120
```

Code structure
--------------
- `interpreter/Lexer.*` - tokenization
- `interpreter/Parser.*` - AST construction
- `interpreter/Interpreter.*` - AST execution/evaluation
- `interpreter/Node/` - AST node definitions (AssignNode, ForNode, PrintNode, FunctionDefNode, ReturnNode, CallNode, etc.)
- `interpreter/File.*` - file reading utilities
