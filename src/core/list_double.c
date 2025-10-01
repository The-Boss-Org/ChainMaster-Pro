#include <stdio.h>
#include <stdlib.h>
#include "../../include/chainmaster.h"

// Insertion triée croissante dans une liste doublement chaînée
DList* dll_insert_sorted(DList* head, int value) {
    DList* node = (DList*)malloc(sizeof(DList));
    if (!node) return head;
    node->data = value;
    node->prev = node->next = NULL;

    if (!head) {
        return node;
    }
    if (value <= head->data) {
        node->next = head;
        head->prev = node;
        return node;
    }
    DList* cur = head;
    while (cur->next && cur->next->data < value) {
        cur = cur->next;
    }
    node->next = cur->next;
    if (cur->next) cur->next->prev = node;
    cur->next = node;
    node->prev = cur;
    return head;
}
