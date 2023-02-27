#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum TokenType { // Won't add more tokens for now
    ERROR_TOKEN,
    END_TOKEN,
    FN_TOKEN,
    ID_TOKEN,
    INFERRED_ATTR_TOKEN,
    SEMICOLON_TOKEN,
    IF_TOKEN,
    ELSE_TOKEN,
    INT_TOKEN,
    FLOAT_TOKEN,
    L_PAREN_TOKEN,
    R_PAREN_TOKEN,
    L_BRACKET_TOKEN,
    R_BRACKET_TOKEN,
    L_CURLY_BRACKET_TOKEN,
    R_CURLY_BRACKET_TOKEN,
    SUM_TOKEN,
    MINUS_TOKEN,
};

struct Token {
    TokenType type = ERROR_TOKEN;
    std::string text;
    size_t length = 0;
};

const char* token_text(TokenType type);

#endif // TOKEN_H
