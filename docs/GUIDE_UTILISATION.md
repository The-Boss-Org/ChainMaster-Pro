# 📚 Guide d'Utilisation - ChainMaster Pro

## 🎯 Introduction

Ce guide vous accompagne dans l'utilisation de la bibliothèque ChainMaster Pro pour maîtriser les listes chaînées en C.

## 🚀 Compilation du Projet

### Compilation Basique
```bash
# Compiler tous les modules
make all

# Nettoyer les fichiers compilés
make clean
```

### Exécution des Démos
```bash
# Demo interface interactive (Exercice 4)
make demo

# Demo complet (tous les 5 exercices)
make demo_all
```

## 📖 Les 5 Exercices Implémentés

### ✅ Exercice 1: Suppression de toutes les occurrences

**Fichier**: `src/core/list_simple.c`

**Fonction**: `SNode* sll_delete_all(SNode* head, int key)`

**Description**: Supprime tous les nœuds contenant la valeur `key` d'une liste simplement chaînée.

**Exemple**:
```c
#include "chainmaster.h"

SNode* liste = NULL;
// Créer: 3 -> 5 -> 3 -> 7 -> 3
liste = sll_insert_sorted(liste, 3);
liste = sll_insert_sorted(liste, 5);
liste = sll_insert_sorted(liste, 3);
liste = sll_insert_sorted(liste, 7);

// Supprimer toutes les occurrences de 3
liste = sll_delete_all(liste, 3);
// Résultat: 5 -> 7
```

**Complexité**: O(n) où n est le nombre d'éléments

---

### ✅ Exercice 2: Insertion triée dans une liste simple

**Fichier**: `src/core/list_simple.c`

**Fonction**: `SNode* sll_insert_sorted(SNode* head, int value)`

**Description**: Insère un élément dans une liste simplement chaînée en maintenant l'ordre croissant.

**Exemple**:
```c
SNode* liste = NULL;
liste = sll_insert_sorted(liste, 5);
liste = sll_insert_sorted(liste, 2);
liste = sll_insert_sorted(liste, 8);
liste = sll_insert_sorted(liste, 1);
// Résultat: 1 -> 2 -> 5 -> 8
```

**Complexité**: O(n) pour trouver la position d'insertion

---

### ✅ Exercice 3: Insertion triée dans une liste double

**Fichier**: `src/core/list_double.c`

**Fonction**: `DList* dll_insert_sorted(DList* head, int value)`

**Description**: Insère un élément dans une liste doublement chaînée en maintenant l'ordre croissant.

**Exemple**:
```c
DList* liste = NULL;
liste = dll_insert_sorted(liste, 10);
liste = dll_insert_sorted(liste, 5);
liste = dll_insert_sorted(liste, 15);
// Résultat: 5 <-> 10 <-> 15
```

**Avantages**: Navigation bidirectionnelle, insertion/suppression optimisée

**Complexité**: O(n)

---

### ✅ Exercice 4: Liste circulaire simplement chaînée

**Fichier**: `src/core/list_circulaire_simple.c`

**Fonctions**:
- `Node* cll_insert_head(Node* head, int value)` - Insertion en tête
- `Node* cll_insert_tail(Node* head, int value)` - Insertion en queue
- `void cll_print(const Node* head)` - Affichage

**Description**: Liste où le dernier nœud pointe vers le premier (circularité).

**Exemple**:
```c
Node* cll = cll_create();
cll = cll_insert_head(cll, 2);  // [2]
cll = cll_insert_tail(cll, 4);  // [2, 4]
cll = cll_insert_head(cll, 1);  // [1, 2, 4]
cll_print(cll);  // Affiche: 1 2 4
cll_free(cll);
```

**Complexité**: O(n) pour l'insertion (doit trouver la queue)

---

### ✅ Exercice 5: Liste circulaire doublement chaînée

**Fichier**: `src/core/list_circulaire_double.c`

**Fonctions**:
- `DNode* cdll_insert_head(DNode* head, int value)` - Insertion en tête O(1)
- `DNode* cdll_insert_tail(DNode* head, int value)` - Insertion en queue O(1)
- `void cdll_print_forward(const DNode* head)` - Affichage avant
- `void cdll_print_backward(const DNode* head)` - Affichage arrière

**Description**: Liste doublement chaînée circulaire - chaque nœud a un lien `prev` et `next`, avec circularité.

**Exemple**:
```c
DNode* cdll = cdll_create();
cdll = cdll_insert_head(cdll, 20);   // [20]
cdll = cdll_insert_tail(cdll, 30);   // [20, 30]
cdll = cdll_insert_head(cdll, 10);   // [10, 20, 30]
cdll_print_forward(cdll);   // 10 20 30
cdll_print_backward(cdll);  // 30 20 10
cdll_free(cdll);
```

**Avantage**: Insertions en tête ET queue en O(1) grâce à la circularité et double liaison

**Complexité**: O(1) pour insertion tête/queue

---

## 🧪 Tests et Validation

### Lancer les Tests
```bash
make test-all
```

### Vérification Mémoire (avec Valgrind sur Linux/Mac)
```bash
make check-memory
```

### Benchmark Performances
```bash
make benchmark
```

## 📁 Structure des Fichiers

```
ChainMaster-Pro/
├── include/
│   ├── structures.h       # Définitions des structures
│   ├── chainmaster.h      # API principale
│   └── interfaces.h       # Interface pour demo interactive
├── src/core/
│   ├── list_simple.c      # Exercices 1 & 2
│   ├── list_double.c      # Exercice 3
│   ├── list_circulaire_simple.c    # Exercice 4
│   ├── list_circulaire_double.c    # Exercice 5
│   └── common.c           # Utilitaires
├── examples/
│   └── demo_complete.c    # Démo des 5 exercices
└── Makefile
```

## 💡 Conseils d'Utilisation

### Gestion de la Mémoire
- **Toujours** libérer la mémoire avec les fonctions `*_free()`
- Vérifier les retours `NULL` en cas d'échec d'allocation
- Utiliser Valgrind pour détecter les fuites mémoire

### Bonnes Pratiques
- Tester les cas limites (liste vide, un seul élément)
- Vérifier les pointeurs avant déréférencement
- Documenter vos fonctions

### Debugging
- Utiliser `printf` pour tracer l'exécution
- Compiler avec `-g` pour le débogage avec GDB
- Activer les warnings: `-Wall -Wextra`

## 🎓 Ressources Supplémentaires

- **THEORIE_LISTES.md** - Concepts théoriques
- **API_REFERENCE.md** - Référence complète de l'API
- Code source commenté dans `src/core/`

## 👥 Support

Pour toute question ou problème:
- Consultez les exemples dans `examples/`
- Lisez les commentaires dans le code source
- Contactez l'équipe de développement

---

**Bon apprentissage avec ChainMaster Pro! 🚀**
