// Encoder Header File:

#ifndef ENCODER_H
#define ENCODER_H

#include"lexer.h"

typedef enum{
    R_TYPE,
    I_TYPE,
    B_TYPE,
    J_TYPE,
    S_TYPE
} Instrformat;

typedef struct{
    char name[10];
    Instrformat format;
    int opcode;
    int funct3;
    int funct7;
} EncodeInstr;

int reg_number(char *reg);

unsigned int encode_R(int rd, int rs1, int rs2, int funct3, int funct7, int opcode);   // Register Encoding
unsigned int encode_I(int rd, int rs1, int imm, int funct3, int opcode);               // Immediate Type Encoding
unsigned int encode_B(int rs1, int rs2, int imm, int funct3, int opcode);               // Branch Type Encoding
unsigned int encode_J(int rd, int imm, int opcode);               // Jump Type Encoding

unsigned int encode(Token tokens[], int count, int pc);     // here count is a measure of number of tokens.

#endif
