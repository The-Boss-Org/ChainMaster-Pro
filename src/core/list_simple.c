#include <stdio.h>
#include <stdlib.h>
#include "../../include/chainmaster.h"

// Supprime toutes les occurrences de 'key' dans une liste simplement chaînée
SNode* sll_delete_all(SNode* head, int key) {
    // Supprimer depuis le début tant que la tête matche
    while (head && head->data == key) {
        SNode* tmp = head;
        head = head->next;
        free(tmp);
    }
    // Parcours et suppression au milieu/fin
    SNode* cur = head;
    while (cur && cur->next) {
        if (cur->next->data == key) {
            SNode* del = cur->next;
            cur->next = del->next;
            free(del);
        } else {
            cur = cur->next;
        }
    }
    return head;
}

// Insertion triée croissante dans une liste simplement chaînée
SNode* sll_insert_sorted(SNode* head, int value) {
    SNode* node = (SNode*)malloc(sizeof(SNode));
    if (!node) return head; // allocation échouée
    node->data = value;
    node->next = NULL;

    if (!head || value <= head->data) {
        node->next = head;
        return node;
    }
    SNode* cur = head;
    while (cur->next && cur->next->data < value) {
        cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
    return head;
}
