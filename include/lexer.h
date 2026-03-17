// lexer.h

#ifndef LEXER_H
#define LEXER_H

#define MAX 500
#define MAX_TOKENS 100

// Type of tokens in an instruction:
typedef enum{
    IDENTIFIER,
    REGISTER,
    IMMEDIATE,
    COMMA,
    LPAREN,     // Left - parantheses
    RPAREN,     // Right - parantheses
    UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    char value[50];
} Token;

void add_token(Token tokens[], int* count, TokenType type, const char* value);
int lexer(char* line, Token tokens[]);

#endif
