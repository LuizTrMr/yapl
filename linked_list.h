#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include "token.h"

struct Node {
    Token token;
    Node* next = nullptr;
};

struct LinkedList {
    Node* head = nullptr;

    void append(Token token);
};

#endif // LINKED_LIST_H
