/*
 * Exemple Simple - ChainMaster Pro
 * Démonstration minimale pour démarrer rapidement
 */

#include <stdio.h>
#include "../include/chainmaster.h"

int main(void) {
    printf("\n=== Exemple Simple - ChainMaster Pro ===\n\n");
    
    // Exemple 1: Liste simple avec suppression
    printf("1. Liste simple - Suppression d'occurrences:\n");
    SNode* list1 = NULL;
    list1 = sll_insert_sorted(list1, 5);
    list1 = sll_insert_sorted(list1, 3);
    list1 = sll_insert_sorted(list1, 7);
    list1 = sll_insert_sorted(list1, 3);
    
    printf("   Avant: ");
    SNode* temp = list1;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    list1 = sll_delete_all(list1, 3);
    printf("\n   Après suppression de 3: ");
    temp = list1;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
    
    // Libérer
    while (list1) { SNode* n = list1; list1 = list1->next; free(n); }
    
    // Exemple 2: Liste circulaire double
    printf("2. Liste circulaire double - Insertion O(1):\n");
    DNode* cdll = cdll_create();
    cdll = cdll_insert_head(cdll, 20);
    cdll = cdll_insert_tail(cdll, 30);
    cdll = cdll_insert_head(cdll, 10);
    
    printf("   Liste: ");
    cdll_print_forward(cdll);
    
    cdll_free(cdll);
    
    printf("\n✅ Exemple terminé avec succès!\n\n");
    return 0;
}
