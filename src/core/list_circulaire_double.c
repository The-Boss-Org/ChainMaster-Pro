#include <stdio.h>
#include <stdlib.h>
#include "../../include/chainmaster.h"

static DNode* make_node(int value) {
    DNode* n = (DNode*)malloc(sizeof(DNode));
    if (!n) return NULL;
    n->data = value;
    n->prev = n->next = NULL;
    return n;
}

DNode* cdll_create(void) {
    return NULL;
}

DNode* cdll_insert_head(DNode* head, int value) {
    DNode* n = make_node(value);
    if (!n) return head;
    if (!head) {
        n->next = n->prev = n;
        return n;
    }
    DNode* tail = head->prev; // en circulaire, prev de head est tail
    n->next = head;
    n->prev = tail;
    tail->next = n;
    head->prev = n;
    return n; // nouvelle tête
}

DNode* cdll_insert_tail(DNode* head, int value) {
    DNode* n = make_node(value);
    if (!n) return head;
    if (!head) {
        n->next = n->prev = n;
        return n;
    }
    DNode* tail = head->prev;
    n->next = head;
    n->prev = tail;
    tail->next = n;
    head->prev = n;
    return head; // tête inchangée
}

void cdll_print_forward(const DNode* head) {
    if (!head) { printf("Liste vide\n"); return; }
    const DNode* cur = head;
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("\n");
}

void cdll_print_backward(const DNode* head) {
    if (!head) { printf("Liste vide\n"); return; }
    const DNode* cur = head->prev; // partir de la fin
    const DNode* stop = head->prev;
    do {
        printf("%d ", cur->data);
        cur = cur->prev;
    } while (cur != stop);
    printf("\n");
}

void cdll_free(DNode* head) {
    if (!head) return;
    DNode* cur = head->next;
    while (cur != head) {
        DNode* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    free(head);
}
