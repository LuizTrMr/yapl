#include "file_handler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "lexer.h"
#include "token.h"

void Lexer::set_token(Token* token, TokenType type, size_t len) {
    token->type   = type;
    token->length = len;
    token->text   = std::string(&content[cursor], len);
    list.push_back(*token);
    cursor += len;
}

bool Lexer::check_literal(const char* literal, TokenType type) {
    if ( strncmp(&content[cursor], literal, strlen(literal)) == 0 ) return true;
    return false;
}

Token Lexer::next_token() {
    Token token = Token{};
    if ( cursor >= content_length ) {
        token.type = END_TOKEN;
        return token;
    }

    // Ignore spaces and tabs (trim left)
    while ( content[cursor] == ' ' || content[cursor] == '\t' ) {
        cursor += 1;
    }

    if ( content[cursor] == '\n' ) {
        cursor += 1;
        line += 1;
        return next_token();
    }

    // +
    if ( content[cursor] == '+' ) {
        set_token(&token, SUM_TOKEN, 1);
        return token;
    }

    // -
    if ( content[cursor] == '-' ) {
        set_token(&token, MINUS_TOKEN, 1);
        return token;
    }

    // [
    if ( content[cursor] == '[' ) {
        set_token(&token, L_BRACKET_TOKEN, 1);
        return token;
    }

    // ]
    if ( content[cursor] == ']' ) {
        set_token(&token, R_BRACKET_TOKEN, 1);
        return token;
    }

    // (
    if ( content[cursor] == '(' ) {
        set_token(&token, L_PAREN_TOKEN, 1);
        return token;
    }

    // )
    if ( content[cursor] == ')' ) {
        set_token(&token, R_PAREN_TOKEN, 1);
        return token;
    }

    // {
    if ( content[cursor] == '{' ) {
        set_token(&token, L_CURLY_BRACKET_TOKEN, 1);
        return token;
    }

    // }
    if ( content[cursor] == '}' ) {
        set_token(&token, R_CURLY_BRACKET_TOKEN, 1);
        return token;
    }

    // fn
    if ( check_literal("fn", FN_TOKEN) ) {
        set_token(&token, FN_TOKEN, 2);
        return token;
    }

    // if
    if ( content[cursor] == 'i' && content[cursor + 1] == 'f' ) {
        set_token(&token, IF_TOKEN, 2);
        return token;
    }

    // else
    if ( content[cursor] == 'e' && content[cursor + 1] == 'l' && content[cursor + 2] == 's' && content[cursor + 3] == 'e' ) {
        set_token(&token, ELSE_TOKEN, 4);
        return token;
    }

    // INT and FLOAT
    if ( isdigit(content[cursor]) ) {
        while ( isdigit(content[token.length+cursor]) ) { // and cursor is less than content_length
            token.length += 1;
        }
        if ( content[token.length+cursor] == '.' ) {
            token.length += 1;
            while ( isdigit(content[token.length+cursor]) ) { // and cursor is less than content_length
                token.length += 1;
            }
            token.type = FLOAT_TOKEN;
        } else {
            token.type = INT_TOKEN;
        }
        token.text = std::string(&content[cursor], token.length);
        cursor += token.length;
        list.push_back(token);
        return token;
    }

    // ID
    if ( content[cursor] == '_' || isalpha(content[cursor]) ) {
        token.type = ID_TOKEN;
        while ( content[token.length+cursor] == '_' || isalnum(content[token.length+cursor]) ) { // and cursor is less than content_length
            token.length += 1;
        }
        token.text = std::string(&content[cursor], token.length);
        list.push_back(token);
        cursor += token.length;
        return token;
    }

    // :=
    if ( content[cursor] == ':' && content[cursor + 1] == '=' ) {
        set_token(&token, INFERRED_ATTR_TOKEN, 2);
        return token;
    }

    // ;
    if ( content[cursor] == ';' ) {
        set_token(&token, SEMICOLON_TOKEN, 1);
        return token;
    }

    // If we reached this section, the token wasn't recognized
    token.text = std::string(&content[cursor], 1);
    return token;
}
