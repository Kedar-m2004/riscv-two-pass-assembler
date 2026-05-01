// parser.c
// (Here we are using 'Table-Driven Parsing')

#include<stdio.h>
#include<string.h>
#include"parser.h"

// Instruction Table (Array Declaration):
Instruction instruction_set[] = {

    // R_TYPE
    {"ADD", 5, {REGISTER, COMMA, REGISTER, COMMA, REGISTER}},
    {"SUB", 5, {REGISTER, COMMA, REGISTER, COMMA, REGISTER}},

    // I_TYPE
    {"ADDI", 5, {REGISTER, COMMA, REGISTER, COMMA, IMMEDIATE}},
    {"JALR", 6, {REGISTER, COMMA, IMMEDIATE, LPAREN, REGISTER, RPAREN}},

    {"LW", 6, {REGISTER, COMMA, IMMEDIATE, LPAREN, REGISTER, RPAREN}},      // LPAREN is left paranthesis

    // S_TYPE
    {"SW", 6, {REGISTER, COMMA, IMMEDIATE, LPAREN, REGISTER, RPAREN}},      // RPAREN is right paranthesis

    // B_TYPE
    {"BEQ", 5, {REGISTER, COMMA, REGISTER, COMMA, IDENTIFIER}},
    {"BNE", 5, {REGISTER, COMMA, REGISTER, COMMA, IDENTIFIER}},

    // J_TYPE
    {"JAL", 3, {REGISTER, COMMA, IDENTIFIER}},

    // HALT INSTRUCTION:
    {"HLT", 0, {}}          // Also counted in R_TYPE, but a custom case
};

// Calculation for number of instructions in the table: 
#define INSTRUCTION_COUNT ( sizeof(instruction_set) / sizeof(instruction_set[0]) )


// Instruction-Parser Function:
int parser(Token tokens[], int count, int line_num){
    /* This function will return:
        '0' for any invalid or unknown opcode.
        '1' for valid opcode.
    */

    for(int i = 0; i<INSTRUCTION_COUNT; i++){

        if(count == 0){
            return 0;
        }

        // Comparing OPCODES from the instruction Database:
        if(strcmp(tokens[0].value, instruction_set[i].name) == 0){      

            //Checking Operand count:
            if( count-1 != instruction_set[i].tok_count ){
                printf("Syntax Error! in line - %d", line_num);
                return 0;
            }

            // Checking pattern:
            // (Using loop to traverse internal array of patterns/instruction-fields)
            for(int j = 0; j<instruction_set[i].tok_count; j++){

                if( tokens[j+1].type != instruction_set[i].pattern[j] ){
                    printf("Syntax Error in line - %d! \nUnexpected token '%s' \n", line_num, tokens[j+1].value);
                    return 0;
                }
            }

            printf(" Instruction Valid!");
            return 1;
        }
    }

    printf("Unknown-Instruction in line - %d", line_num);
    return 0;
}
