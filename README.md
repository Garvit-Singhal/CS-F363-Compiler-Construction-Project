# Custom Language Compiler (CS F363: BITS Pilani)

This repository contains the first phase of a custom compiler built in C for the **CS F363 Compiler Construction** course. It implements a robust Lexical Analyzer (Scanner) and a Syntax Analyzer (Parser) capable of generating an in-order parse tree with Panic-Mode error recovery.

## 🚀 Features

* **Lexical Analyzer (Scanner):**
    * **Twin-Buffer System:** Optimized disk I/O reads using a 4KB twin-buffer mechanism.
    * **DFA-based Tokenization:** Custom state machine to process identifiers, operators, keywords, and real numbers accurately.
    * **Symbol Table:** Implemented using a fast `djb2` hash function for keyword management.
* **Syntax Analyzer (Parser):**
    * **LL(1) Parsing:** Predictive, top-down parsing using pre-computed FIRST and FOLLOW sets.
    * **Parse Tree Generation:** Constructs and exports a complete N-ary parse tree in a strictly formatted tabular layout.
* **Error Handling & Recovery:**
    * **Lexical Errors:** Detects length violations and unknown symbol patterns.
    * **Panic-Mode Recovery:** Safely recovers from syntax errors using synchronization tokens to prevent cascading crashes.
* **Performance Metrics:** Tracks total CPU execution time (ticks and seconds) for lexical and syntax analysis.

## 📁 File Structure

    ├── driver.c          # Main entry point and menu-driven interface
    ├── lexer.c           # Lexical Analyzer implementation (DFA, Buffers, Symbol Table)
    ├── lexer.h           # Lexer function prototypes
    ├── lexerDef.h        # Token enumerations and Token struct definitions
    ├── parser.c          # Syntax Analyzer implementation (Parse Table, Tree Generation)
    ├── parser.h          # Parser function prototypes
    ├── parserDef.h       # Parse Tree node structures and grammar definitions
    ├── makefile          # GNU build script
    └── README.md         # Project documentation


## ⚙️ Build Instructions

This project includes a `makefile` for streamlined compilation.

To compile the project and generate the executable (`stage1exe`), simply run:
    make

To clean up the directory (remove object files, the executable, and generated text files), run:
    make clean

## 💻 Usage

Run the executable with two command-line arguments: the input source code file and the output file for the parse tree.

    ./stage1exe <input_testcase.txt> <output_parsetree.txt>

*Example:*
    ./stage1exe testcase1.txt parsetreeOutFile.txt

### 🎛️ Driver Menu Options
Once executed, the program presents a menu-driven interface with the following options:

* **`0` - Exit:** Terminates the compiler.
* **`1` - Remove Comments:** Strips all `%` comments from the source file, prints the clean code to the console, and saves it to `clean_source.txt`.
* **`2` - Print Token List:** Runs the Lexer and prints the token stream to the console, including lexical errors.
* **`3` - Parse Code:** Runs the Parser. If syntactically correct, it generates the parse tree and writes it to the specified output file. If errors are found, they are dumped to a `listoferrors_*.txt` file.
* **`4` - Execution Time:** Runs both the Lexer and Parser and prints the total CPU time taken.

## 📋 Parse Tree Output Format
When Option 3 is selected on syntactically valid code, the parse tree is printed to the output file using an in-order traversal in the following format:
`Lexeme | LineNo | TokenName | ValueIfNumber | ParentNodeSymbol | isLeafNode(yes/no) | NodeSymbol`

---
*Developed for BITS Pilani - Compiler Construction.*
