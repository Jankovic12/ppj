# Matrix Expression Interpreter

A compiler-style interpreter for a domain-specific language (DSL) for matrix arithmetic, written in C++ using **Flex** (lexer) and **Bison** (LALR parser).

## Features

- Arithmetic operators: `+`, `-`, `*` with scalar broadcasting (1×1 matrix acts as scalar)
- Element-wise multiplication (`.*`)
- Transposition (`'`)
- Submatrix extraction (`A[row_from:row_to, col_from:col_to]`)
- Equality and inequality comparison (`==`, `!=`)
- Variable assignment
- Built-in functions: `size()`, `rows()`, `cols()`
- Graceful error handling with descriptive messages for dimension mismatches

## How It Works

The project follows a classic compiler front-end architecture:

1. **Lexer** (`lexer.l`) — tokenizes input using Flex; recognizes identifiers, numbers, operators, keywords and comments (`%`)
2. **Parser** (`parser.ypp`) — LALR(1) grammar via Bison with defined operator precedence and associativity
3. **Semantic layer** (`Matrix.cpp / Matrix.hpp`) — evaluates expressions using overloaded C++ operators; scalars are represented as 1×1 matrices for uniform handling

## Build

Requires `flex`, `bison`, and `g++`.

```bash
make
```

## Usage

Supports both file input and interactive (REPL) mode.

```bash
./parser < test
```

**Interactive:**
```bash
./parser
```

### Example input

```
% matrix definition
x = [1, 2, 3; 4, 5, 6; 7, 8, 9]
y = [2, 2, 2; 4, 4, 3; 8, 8, 8]

% arithmetic
x + y
3 * x
x .* y

% transposition
x'

% submatrix: rows 1..1, cols 0..2
z = x[1:1, 0:2]

% built-in functions
size(x)
rows(x')
cols([1,2,3; 4,5,6])

% comparison
x == y
x != y
```

## Project Structure

```
matrix/
├── lexer.l        # Flex lexer — tokenization rules
├── parser.ypp     # Bison parser — LALR(1) grammar and semantic actions
├── Matrix.hpp     # Matrix class declaration
├── Matrix.cpp     # Matrix operations (operator overloading, scalar broadcasting)
├── Makefile       # Build configuration
└── test           # Sample input with various expression types
```

## Technologies

- **C++** — core implementation, operator overloading, scalar broadcasting
- **Flex** — lexical analysis
- **Bison** — LALR(1) parser generation
- **Make** — build system
