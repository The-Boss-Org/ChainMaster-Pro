#include <stdio.h>
#include <stdlib.h>
#include "../../include/chainmaster.h"

// Utilitaires communs pour toutes les listes

// Affichage d'une liste simplement chaînée standard
void print_simple_list(const Node* head) {
    const Node* cur = head;
    printf("Liste: ");
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// Libération d'une liste simplement chaînée standard
void free_simple_list(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Affichage d'une liste doublement chaînée standard
void print_double_list(const DNode* head) {
    const DNode* cur = head;
    printf("Liste: NULL <-> ");
    while (cur) {
        printf("%d <-> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// Libération d'une liste doublement chaînée standard
void free_double_list(DNode* head) {
    while (head) {
        DNode* tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Compter les éléments dans une liste simple
int count_simple_list(const Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Compter les éléments dans une liste circulaire simple
int count_circular_list(const Node* head) {
    if (!head) return 0;
    int count = 1;
    const Node* cur = head->next;
    while (cur != head) {
        count++;
        cur = cur->next;
    }
    return count;
}
