#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include "linked_list.h"
#include "token.h"

struct Parser {
};

Parser::parse(LinkedList list) {
    Node* node = list.head;
    if ( node->token.type == FN_TOKEN ) {
        parse_fn(node);
    }
}

Parser::parse_fn(Node* node) {
    Node* id;
    if (  node->next != nullptr ) id = node->next;

    if ( id->token.type != ID_TOKEN ) {
        printf("Expected ID_TOKEN, got %s instead\n", token_text(id->token.type));
        exit(1);
    }

    Node* l_paren;
    if (  id->next != nullptr ) l_paren = id->next;

    if ( l_paren->token.type != L_PAREN_TOKEN ) {
        printf("Expected L_PAREN_TOKEN, got %s instead\n", token_text(l_paren->token.type));
        exit(1);
    }

    if (  l_paren->next != nullptr ) parse_expressions(l_paren->next);


}

Parser::parse_expressions(Node* node) {
    // Check if it is an asssignment
}

#endif // PARSER_H
