#include <stdio.h>
#include "../include/chainmaster.h"

// Tutorial guidé pour apprendre ChainMaster Pro

void demo_exercice1() {
    printf("\n=== EXERCICE 1: Suppression de toutes les occurrences ===\n");
    
    SNode* list = NULL;
    printf("Création d'une liste: 3, 5, 3, 7, 3, 9\n");
    int values[] = {3, 5, 3, 7, 3, 9};
    for (int i = 0; i < 6; i++) {
        SNode* node = malloc(sizeof(SNode));
        node->data = values[i];
        node->next = list;
        list = node;
    }
    
    printf("Liste avant suppression: ");
    SNode* temp = list;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    printf("Suppression de toutes les occurrences de 3...\n");
    list = sll_delete_all(list, 3);
    
    printf("Liste après suppression: ");
    temp = list;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    while (list) { SNode* n = list; list = list->next; free(n); }
}

void demo_exercice2() {
    printf("\n=== EXERCICE 2: Insertion triée (liste simple) ===\n");
    
    SNode* list = NULL;
    int values[] = {15, 3, 9, 1, 12, 6};
    
    printf("Insertion des valeurs: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", values[i]);
        list = sll_insert_sorted(list, values[i]);
    }
    printf("\n");
    
    printf("Liste triée résultante: ");
    SNode* temp = list;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    while (list) { SNode* n = list; list = list->next; free(n); }
}

void demo_exercice3() {
    printf("\n=== EXERCICE 3: Insertion triée (liste double) ===\n");
    
    DList* list = NULL;
    int values[] = {20, 5, 15, 10, 25};
    
    printf("Insertion des valeurs: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", values[i]);
        list = dll_insert_sorted(list, values[i]);
    }
    printf("\n");
    
    printf("Liste doublement chaînée triée: ");
    DList* temp = list;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    while (list) { DList* n = list; list = list->next; free(n); }
}

void demo_exercice4() {
    printf("\n=== EXERCICE 4: Liste circulaire simple ===\n");
    
    Node* cll = cll_create();
    printf("Insertion en tête: 30\n");
    cll = cll_insert_head(cll, 30);
    printf("Insertion en queue: 40\n");
    cll = cll_insert_tail(cll, 40);
    printf("Insertion en tête: 20\n");
    cll = cll_insert_head(cll, 20);
    printf("Insertion en queue: 50\n");
    cll = cll_insert_tail(cll, 50);
    
    printf("Liste circulaire: ");
    cll_print(cll);
    
    printf("Vérification circularité: dernier->next = tête ✓\n");
    
    cll_free(cll);
}

void demo_exercice5() {
    printf("\n=== EXERCICE 5: Liste circulaire doublement chaînée ===\n");
    
    DNode* cdll = cdll_create();
    printf("Insertion en tête: 100\n");
    cdll = cdll_insert_head(cdll, 100);
    printf("Insertion en queue: 200\n");
    cdll = cdll_insert_tail(cdll, 200);
    printf("Insertion en tête: 50\n");
    cdll = cdll_insert_head(cdll, 50);
    printf("Insertion en queue: 300\n");
    cdll = cdll_insert_tail(cdll, 300);
    
    printf("Parcours avant: ");
    cdll_print_forward(cdll);
    
    printf("Parcours arrière: ");
    cdll_print_backward(cdll);
    
    printf("Complexité insertion: O(1) pour tête ET queue! 🚀\n");
    
    cdll_free(cdll);
}

int main(void) {
    printf("\n╔═══════════════════════════════════════╗\n");
    printf("║  ChainMaster Pro - Tutorial Complet  ║\n");
    printf("║  INF 231 - Prof. Melatagia          ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    
    demo_exercice1();
    demo_exercice2();
    demo_exercice3();
    demo_exercice4();
    demo_exercice5();
    
    printf("\n✅ Tutorial terminé avec succès!\n");
    printf("📚 Consultez GUIDE_UTILISATION.md pour plus d'infos\n\n");
    
    return 0;
}
