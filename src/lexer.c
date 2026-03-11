#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"lexer.h"

// Lexer tokenizes the input string:
int lexer(char* line, Token tokens[]){

    int count = 0;
    char* ptr = line;

    while(*ptr){

        // Handling whitespaces (per line):
        while(isspace(*ptr)){                   // Skipping the blank spaces
            ptr++;
        }

        // End of string:
        if(*ptr == '\0')        break;

        // Handling comma:
        if(*ptr == ','){

            tokens[count].type = COMMA;
            strcpy(tokens[count++].value, ",");

            ptr++;
            continue;
        }

        // Handling Left Parantheses:
        if(*ptr == '('){
            tokens[count].type = LPAREN;
            strcpy(tokens[count++].value, ptr);
            ptr++;
            continue;
        }

        // Handling Right Parantheses:
        if(*ptr == ')'){
            tokens[count].type = RPAREN;
            strcpy( tokens[count++].value, ptr);
            ptr++;
            continue;
        }

     // Extracting words:
        char buffer[50];
        int i = 0;

        // Word Extracting Loop:
        while( (*ptr)&&(!isspace(*ptr))&&(*ptr != ',')&&(*ptr != '(')&&(*ptr != ')') ){
            buffer[i++] = *ptr;
            ptr++;
        }
        buffer[i] = '\0';

        if(i == 0){
            continue;
        }


        // Classifying words as tokens:
        if( (buffer[0] == 'R')&&isdigit(buffer[1]) ){
            tokens[count].type = REGISTER;
        }
        else if( isdigit(buffer[0]) || ((buffer[0] == '-')&&isdigit(buffer[1]) ) ){
            tokens[count].type = IMMEDIATE;
        }
        else if( isalpha(buffer[0]) ){
            tokens[count].type = IDENTIFIER;
        }
        else{
            tokens[count].type = UNKNOWN;
        }

        strcpy(tokens[count++].value, buffer);
    }

    return count;
}
