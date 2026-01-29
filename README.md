# Atlas Compiler

![Language](https://img.shields.io/badge/language-C++17-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Build](https://img.shields.io/badge/build-CMake-orange.svg)

**Atlas** is an educational compiler built from scratch in modern C++. It is designed to demonstrate core compiler concepts including lexical analysis, recursive descent parsing, and Abstract Syntax Trees (AST) using robust memory management.

---

## 🚀 Features

* **Lexer:** Converts raw source code into a stream of categorized tokens.
* **Parser:** Implements a Recursive Descent parser to handle complex grammar.
* **AST:** Builds a hierarchical tree structure using `std::unique_ptr` for automatic memory management (RAII).
* **Error Reporting:** Provides detailed syntax errors with line and column offsets.
* **Zero Dependencies:** Built using only the C++ Standard Library.

---

## 📂 Project Structure

The project follows a standard C++ directory layout:

- **include/**: Header files (.h) defining interfaces (Lexer, Token, AST).
- **src/**: Source files (.cpp) implementing the logic.
- **examples/**: Sample `.atlas` scripts to test the language.
- **CMakeLists.txt**: Build configuration.

---

## 🛠️ Build Instructions

Atlas uses **CMake** as its build system. You will need a C++ compiler (like GCC, Clang, or MSVC) installed.

### 1. Clone the Repository
```bash
git clone https://github.com/Stellar-9/Atlas.git
cd Atlas
```

### 2. Compile the Project
```bash
# Create a build directory to keep the project clean
mkdir build
cd build

# Generate build files
cmake ..

# Compile the executable
cmake --build .
```

---

## 💻 How to Run

Once compiled, you can run the compiler from the command line.

**Usage:**
```bash
# Windows
.\Debug\Atlas.exe

# Linux / Mac
./Atlas
```

---

## 📝 Syntax Example

Atlas supports variable declarations, control flow, and mathematical expressions.

```cpp
// Variable Declaration
int x = 10;
int y = 5;

// While Loops
while (x > y) {
    x = x - 1;
}

// Complex Math
int result = (10 * 2) + (50 / 5);
return result; 
```

---

## 🧠 Technical Details

### The Pipeline
1.  **Lexical Analysis:** The `Lexer` reads the source string and produces a list of Tokens.
2.  **Parsing:** The `Parser` consumes tokens and builds an **Abstract Syntax Tree (AST)**.
    * *Technique:* Recursive Descent.
    * *Memory:* Nodes are owned via `std::unique_ptr`, preventing memory leaks.
3.  **Code Generation:** (In Development) The compiler traverses the AST to generate machine code or bytecode.