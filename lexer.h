#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include "linked_list.h"

struct Lexer {
    char* content;
    size_t content_length = 0;
    size_t cursor = 0;
    size_t line = 1;

    LinkedList list = {};

    Token next_token();
    void set_token(Token* token, TokenType type, size_t len);

    // Unimplemented
    bool check_literal(const char* literal, TokenType type);
    Token peek_next_token();
    void eat_token();
};

#endif // LEXER_H
