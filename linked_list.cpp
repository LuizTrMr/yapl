#include <string>

#include "linked_list.h"

void LinkedList::append(Token token) {
    Node* new_node = new Node;
    new_node->token = token;
    if ( !head ) {
        head = new Node;
        head->token = new_node->token;
    } else {
        Node* node = head;
        while ( node->next ) node = node->next;
        node->next = new_node;
    }
}
