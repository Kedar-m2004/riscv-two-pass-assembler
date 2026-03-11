// parser.h

#ifndef PARSER_H
#define PARSER_H

#include"lexer.h"

#define FIELDS 10

// Instruction Format:
typedef struct{
    char name[10];
    int tok_count;
    TokenType pattern[FIELDS];
} Instruction;

int parser(Token tokens[], int count, int line_num);

#endif
