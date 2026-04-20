# Polynomial Expression Interpreter

A compiler-style interpreter for a domain-specific language (DSL) for polynomial arithmetic, written in C++ using **Flex** (lexer) and **Bison** (LALR parser).

## Features

- Arithmetic operators: `+`, `-`, `*`
- Derivative (`p'`)
- Definite integral (`int(p, c)`) — returns antiderivative with constant `c`
- Evaluation at a point (`p[x]`)
- Degree query (`deg(p)`)
- Equality and inequality comparison (`==`, `!=`)
- Variable declaration (`poly`), assignment, and monic monomial initialization (`poly p(n)` creates `x^n`)
- `print()` statement for explicit output

## How It Works

The project follows a classic compiler front-end architecture:

1. **Lexer** (`lexer.l`) — tokenizes input using Flex; recognizes keywords (`poly`, `int`, `deg`, `print`), identifiers, numbers and operators
2. **Parser** (`parser.ypp`) — LALR(1) grammar via Bison with operator precedence for arithmetic, unary minus, derivative and indexing
3. **Semantic layer** (`Polinom.cpp / Polinom.hpp`) — evaluates polynomial expressions using overloaded C++ operators

## Build

Requires `flex`, `bison`, and `g++`.

```bash
make
```

## Usage

Supports both file input and interactive (REPL) mode.

**File input:**
```bash
./parser < test
```

**Interactive:**
```bash
./parser
```

### Example input

```
% declare polynomials (coefficients from highest to lowest degree)
poly p = <1, 2, 3>;
poly q;
poly r(5);          % creates x^5

% print
print(p);

% arithmetic
poly s = 2*p - q*p;

% derivative
poly t = s';
print(t);

% integral with constant 3
print(int(p, 3));

% evaluate at point 2.5
print(p[2.5]);

% degree
print(deg(p));

% comparison
3*p == int(q, 2);
s' != int(<-3.4, 2.7, 0, 7.6>, 2);
```

## Project Structure

```
polynomials/
├── lexer.l        # Flex lexer — tokenization rules
├── parser.ypp     # Bison parser — LALR(1) grammar and semantic actions
├── Polinom.hpp    # Polynomial class declaration
├── Polinom.cpp    # Polynomial operations (operator overloading)
├── Makefile       # Build configuration
└── test           # Sample input with various expression types
```

## Technologies

- **C++** — core implementation, operator overloading
- **Flex** — lexical analysis
- **Bison** — LALR(1) parser generation
- **Make** — build system
