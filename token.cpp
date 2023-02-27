#include "token.h"
#include <stdio.h>


const char* token_text(TokenType type) {
    switch (type) {
        case ERROR_TOKEN: return "ERROR_TOKEN";
        case END_TOKEN: return "END_TOKEN";
        case FN_TOKEN: return "FN_TOKEN";
        case ID_TOKEN: return "ID_TOKEN";
        case INFERRED_ATTR_TOKEN: return "INFERRED_ATTR_TOKEN";
        case SEMICOLON_TOKEN: return "SEMICOLON_TOKEN";
        case IF_TOKEN: return "IF_TOKEN";
        case ELSE_TOKEN: return "ELSE_TOKEN";
        case INT_TOKEN: return "INT_TOKEN";
        case FLOAT_TOKEN: return "FLOAT_TOKEN";
        case L_PAREN_TOKEN: return "L_PAREN_TOKEN";
        case R_PAREN_TOKEN: return "R_PAREN_TOKEN";
        case L_BRACKET_TOKEN: return "L_BRACKET_TOKEN";
        case R_BRACKET_TOKEN: return "R_BRACKET_TOKEN";
        case L_CURLY_BRACKET_TOKEN: return "L_CURLY_BRACKET_TOKEN";
        case R_CURLY_BRACKET_TOKEN: return "R_CURLY_BRACKET_TOKEN";
        case SUM_TOKEN: return "SUM_TOKEN";
        case MINUS_TOKEN: return "MINUS_TOKEN";
        default: {
            printf("ERROR: Missing text for token enum of value: %d\n", type);
            exit(1);
        }
    }
}
