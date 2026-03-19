// CS F363: Compiler Construction
// Group no. 37
// 2022B4A70496P Garvit Singhal
// 2023A7PS0577P Raunit Raj
// 2023A7PS0613P Rishita Sachan
// 2023A7PS0622P Ranvijay Tanwar
// 2023A7PS0655P Rishabh Sharma
// 2023A7PS0605P Aayush Garg

// parserDef.h
// Data definitions and structures for the Syntax Analyzer.
// This file defines the N-ary Parse Tree node, the Grammar Rule
// representation, and the Error tracking structures.

#ifndef PARSERDEF_H
#define PARSERDEF_H

#include "lexerDef.h"

// Max symbols on the right-hand side of any grammar rule is well below 15
#define MAX_CHILDREN 15
// Stack size for the LL(1) Pushdown Automaton (needs to handle deep recursion)
#define MAX_STACK 4096
// Maximum number of syntax/lexical errors we will log to the console/file
#define MAX_ERRORS 500

// Parse Tree Node Structure
// We use an N-ary tree approach since LL(1) rules can have variable RHS lengths.
typedef struct parseTreeNode {
    char symbol[50];         // The string name of the Non-Terminal or Terminal
    Token tk;                // Holds the actual token data (lexeme, line, value) if this is a leaf
    int isLeaf;              // Flag: 1 if it's a terminal/epsilon, 0 if it's a non-terminal

    struct parseTreeNode *parent;                 // Pointer up the tree
    struct parseTreeNode *children[MAX_CHILDREN]; // Pointers down to the expanded rule symbols
    int childCount;                               // number of children this node currently has
} parseTreeNode;

// Grammar Rule Representation
// This defines what a single rule looks like when pulled from the Parse Table.

typedef struct {
    int rhs[10];          // Array of RHS symbols (Enum values: TokenTypes or Non-Terminal IDs)
    int isTerminal[10];   // 1 if the corresponding rhs[i] is a Terminal, 0 if Non-Terminal
    int rhsCount;         // The total number of symbols on the RHS of this specific rule
} GrammarRule;

// Panic Mode Error Tracking
// Simple structure to store errors so we can deduplicate them and print them together at the end.
typedef struct {
    int line;             // Where the syntax or lexical error occurred
    char message[256];    // Formatted error string
} CompilerError;

#endif
