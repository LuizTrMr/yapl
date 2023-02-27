// TODO(1): Add comments with '//' and '/* */'
#include "file_handler.h"
#include "lexer.h"
#include "token.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

int main(int arc, char* argv[]) {
    if (arc < 2) {
        printf("Need to pass a file!\n"); exit(1);
    }
    FILE* f = fopen(argv[1], "r");

    char* program = read_whole_file(f);
    printf("---\n");
    printf("%s", program);
    printf("---\n");
    Lexer lexer = Lexer{};
    lexer.content = program;
    lexer.content_length = strlen(program);

    Token token = lexer.next_token();
    while ( token.type != END_TOKEN ) {
        if ( token.type == ERROR_TOKEN ) {
            printf("Found unexpected token at line(%zu): %s\n", lexer.line, token.text.c_str());
            exit(1);
        }

        printf("Token read = %s (Type: %s)\n", token.text.c_str(), token_text(token.type));
        token = lexer.next_token();
    }
    printf("Reached end of file\n");

    printf("List of tokens:::\n");
    Node* node = lexer.list.head;
    printf("[");
    while ( node->next != nullptr ) {
        printf(" %s,", node->token.text.c_str());
        node = node->next;
    }
    printf(" %s ]\n", node->token.text.c_str());

    free(program);
    fclose(f);
    return 0;
}
