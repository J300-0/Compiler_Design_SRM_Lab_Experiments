# Copilot Instructions for Compiler Design

Compiler design lab experiments. Requires MinGW (gcc/g++), win_flex_bison, and Python.

---

## Experiment 4: Lexical Analysis with Flex

**Location:** `Compiler Design code exp 4 from q8-15/`

**Files:** `q8.l` through `q15.l` - Each demonstrates a different lexical pattern.

| File | Purpose |
|------|---------|
| `q8.l` | Identify uppercase vs lowercase letters |
| `q9.l` | Classify input as digit, word, or mixed |
| `q10.l` | Check well-formed parentheses |
| `q11.l` | Match positive closure of 'a' |
| `q12.l` - `q15.l` | Additional lexical patterns |

**Build & Run:**
```bash
flex q8.l
gcc lex.yy.c -o q8.exe
./q8.exe
```

**Conventions:**
- Standard `.l` structure: `%{ C code %}`, `%%`, rules, `%%`, main
- Always implement `yywrap()` returning 1
- Access matched text via `yytext`

---

## Experiment 5: Left Recursion Removal

**Location:** `experiment5.cpp`

**Purpose:** Removes left recursion from grammar productions.

**Build & Run:**
```bash
g++ -g experiment5.cpp -o experiment5.exe
./experiment5.exe
```

**Input Format:** Hardcoded productions in the form `s+s`, `s*s`, `a` where `s` is the non-terminal.

---

## Experiment 6: LL(1) Parser and Calculator

**Location:** `Exp6/`

### Part A: Flex+Bison Calculator
**Files:** `calculator.l` (lexer), `calculator.y` (parser)

**Build & Run:**
```bash
bison -d calculator.y
flex calculator.l
gcc calculator.tab.c lex.yy.c -o calculator.exe
./calculator.exe
```

**Conventions:**
- Lexer includes `calculator.tab.h` for token definitions
- Parser uses `%union { float fval; }` for semantic values
- Precedence: `%left '+' '-'` then `%left '*' '/'`
- Access values via `$1`, `$2`, `$$`

### Part B: LL(1) Parser Generator (Python)
**File:** `ll1.py`

**Run:**
```bash
python ll1.py
```

**Input Format:**
- Grammar as dictionary: `{'S': [['A', 'B', 'c']], 'A': [['a'], ['e']]}`
- Epsilon represented as `'e'`
- End marker is `'$'`

---

## Experiment 7: FIRST and FOLLOW Sets

**Location:** `exp7.c`

**Purpose:** Computes FIRST and FOLLOW sets for a context-free grammar.

**Build & Run:**
```bash
gcc -g exp7.c -o exp7.exe
./exp7.exe
```

**Input Format:**
- Enter number of productions, then each production
- Format: `E=TR` (uses `=` as separator, not `->`)
- Epsilon represented as `#`
- Non-terminals: uppercase (A-Z)
- Terminals: lowercase or symbols

---

## Experiment 9: Shift-Reduce Parsing

**Location:** `exp9.cpp`

**Purpose:** Demonstrates bottom-up shift-reduce parsing with stack visualization.

**Build & Run:**
```bash
g++ -g exp9.cpp -o exp9.exe
./exp9.exe
```

**Input Format:**
- Productions use `->` separator: `S->aSb`
- Enter number of productions, then productions, then input string

**Output:** Table showing Stack, Input, and Action (Shift/Reduce/Accept/Reject)

---

## Experiment 10: LR(0) Item Sets

**Location:** `exp10.cpp`

**Purpose:** Generates augmented grammar and initial LR(0) closure (I0).

**Build & Run:**
```bash
g++ -g exp10.cpp -o exp10.exe
./exp10.exe
```

**Input Format:**
- Productions use `->` separator: `S->AA`
- First production's LHS becomes start symbol
- Augmented with `S'->S`

**Output:** Numbered productions, augmented grammar, and I0 items with dot notation (`•`)
