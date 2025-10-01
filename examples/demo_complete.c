#include <stdio.h>
#include <stdlib.h>
#include "../include/chainmaster.h"

static void print_sll(const SNode* head) {
    const SNode* cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

static void print_dll_forward(const DList* head) {
    const DList* cur = head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main(void) {
    // Exercice 1 & 2: Liste simplement chaînée
    SNode* sll = NULL;
    int sll_values[] = {5, 3, 7, 3, 9, 3, 1};
    for (size_t i = 0; i < sizeof(sll_values)/sizeof(sll_values[0]); ++i) {
        sll = sll_insert_sorted(sll, sll_values[i]);
    }
    printf("SLL triée: ");
    print_sll(sll);
    sll = sll_delete_all(sll, 3);
    printf("SLL après suppression de 3: ");
    print_sll(sll);
    while (sll) { SNode* n = sll; sll = sll->next; free(n); }

    // Exercice 3: Liste doublement chaînée triée
    DList* dll = NULL;
    int dll_values[] = {10, 2, 8, 4, 6};
    for (size_t i = 0; i < sizeof(dll_values)/sizeof(dll_values[0]); ++i) {
        dll = dll_insert_sorted(dll, dll_values[i]);
    }
    printf("DLL triée: ");
    print_dll_forward(dll);
    // free dll
    while (dll) { DList* n = dll; dll = dll->next; free(n); }

    // Exercice 4: Liste simplement chaînée circulaire - insertion tête/queue
    Node* cll = cll_create();
    cll = cll_insert_head(cll, 2);
    cll = cll_insert_tail(cll, 4);
    cll = cll_insert_head(cll, 1);
    cll = cll_insert_tail(cll, 5);
    printf("CLL: ");
    cll_print(cll);
    cll_free(cll);

    // Exercice 5: Liste doublement chaînée circulaire - insertion tête/queue
    DNode* cdll = cdll_create();
    cdll = cdll_insert_head(cdll, 20);
    cdll = cdll_insert_tail(cdll, 30);
    cdll = cdll_insert_head(cdll, 10);
    cdll = cdll_insert_tail(cdll, 40);
    printf("CDLL avant: ");
    cdll_print_forward(cdll);
    printf("CDLL arrière: ");
    cdll_print_backward(cdll);
    cdll_free(cdll);

    return 0;
}
