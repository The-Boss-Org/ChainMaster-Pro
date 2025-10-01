# 📖 API Reference - ChainMaster Pro

## Header Principal: `chainmaster.h`

### Exercice 1 & 2: Liste Simplement Chaînée

#### `SNode* sll_delete_all(SNode* head, int key)`
Supprime toutes les occurrences de `key` dans la liste.
- **Paramètres**: `head` (tête de liste), `key` (valeur à supprimer)
- **Retour**: Nouvelle tête de liste
- **Complexité**: O(n)

#### `SNode* sll_insert_sorted(SNode* head, int value)`
Insère `value` en maintenant l'ordre croissant.
- **Paramètres**: `head` (tête), `value` (valeur)
- **Retour**: Nouvelle tête
- **Complexité**: O(n)

### Exercice 3: Liste Doublement Chaînée

#### `DList* dll_insert_sorted(DList* head, int value)`
Insertion triée dans liste doublement chaînée.
- **Paramètres**: `head`, `value`
- **Retour**: Nouvelle tête
- **Complexité**: O(n)

### Exercice 4: Liste Circulaire Simple

#### `Node* cll_create(void)`
Crée une liste circulaire vide.
- **Retour**: NULL

#### `Node* cll_insert_head(Node* head, int value)`
Insertion en tête O(n).

#### `Node* cll_insert_tail(Node* head, int value)`
Insertion en queue O(n).

#### `void cll_print(const Node* head)`
Affiche la liste circulaire.

#### `void cll_free(Node* head)`
Libère toute la mémoire.

### Exercice 5: Liste Circulaire Double

#### `DNode* cdll_create(void)`
Crée une liste vide.

#### `DNode* cdll_insert_head(DNode* head, int value)`
Insertion en tête O(1).

#### `DNode* cdll_insert_tail(DNode* head, int value)`
Insertion en queue O(1).

#### `void cdll_print_forward(const DNode* head)`
Affichage dans le sens normal.

#### `void cdll_print_backward(const DNode* head)`
Affichage dans le sens inverse.

#### `void cdll_free(DNode* head)`
Libère la mémoire.

## Structures

### `Node` (Liste Simple)
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

### `DNode` (Liste Double)
```c
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;
```

## Utilisation

```c
#include "chainmaster.h"

int main() {
    // Exercice 1 & 2
    SNode* sll = NULL;
    sll = sll_insert_sorted(sll, 5);
    sll = sll_delete_all(sll, 5);
    
    // Exercice 5
    DNode* cdll = cdll_create();
    cdll = cdll_insert_head(cdll, 10);
    cdll_print_forward(cdll);
    cdll_free(cdll);
    
    return 0;
}
```
