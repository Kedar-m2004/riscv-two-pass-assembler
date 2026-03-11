// Header file for symbol table

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_SYMBOLS 100

// Structure for Symbol-Table:
typedef struct{
    char label[50];
    int address;
} Symbol;

void trim(char* str);

void add_symbol(char *label, int address);
int find_symbol(char *label);
void print_symbol_table();

#endif
