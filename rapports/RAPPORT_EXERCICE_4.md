# 📄 Rapport - Exercice 4
## Insertion en Tête et en Queue dans une Liste Circulaire Simplement Chaînée

---

## 📋 Informations Générales

| Item | Détail |
|------|--------|
| **Exercice** | 4 |
| **Titre** | Insertion en tête et en queue dans une liste simplement chaînée circulaire |
| **Type de liste** | Liste circulaire simplement chaînée |
| **Responsable** | HENDRIX MENOUNGA LEGRAND (24G2579) |
| **Statut** | ✅ Complété et testé |
| **Date** | 25 septembre 2025 |

---

## 🎯 Objectif de l'Exercice

Implémenter les opérations d'insertion en tête et en queue dans une **liste circulaire** où le dernier nœud pointe vers le premier (pas de NULL), permettant un parcours infini.

---

## 💻 Implémentation

### Fichier Source
**Emplacement**: `src/core/list_circulaire_simple.c`

### Structure de Données
```c
typedef struct Node {
    int data;
    struct Node* next;  // Pointe toujours vers un nœud (jamais NULL)
} Node;
```

### Caractéristique Principale
```
Circulaire: dernier->next == premier
Pas de NULL (sauf si liste vide)
```

### Fonctions Implémentées

#### 1. Création
```c
Node* cll_create(void) {
    return NULL;  // Liste vide initialement
}
```

#### 2. Insertion en Tête
```c
Node* cll_insert_head(Node* head, int value) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    if (!nouveau) return head;
    nouveau->data = value;
    
    if (!head) {
        nouveau->next = nouveau;  // Pointe vers lui-même
        return nouveau;
    }
    
    // Trouver le dernier nœud
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = nouveau;  // Dernier pointe vers nouveau
    nouveau->next = head;  // Nouveau pointe vers ancien head
    return nouveau;        // Nouveau devient head
}
```

#### 3. Insertion en Queue
```c
Node* cll_insert_tail(Node* head, int value) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    if (!nouveau) return head;
    nouveau->data = value;
    
    if (!head) {
        nouveau->next = nouveau;
        return nouveau;
    }
    
    // Trouver le dernier nœud
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = nouveau;  // Ancien dernier pointe vers nouveau
    nouveau->next = head;  // Nouveau pointe vers head
    return head;           // Head reste inchangé
}
```

#### 4. Affichage
```c
void cll_print(const Node* head) {
    if (!head) {
        printf("Liste vide\n");
        return;
    }
    const Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Stop quand on revient au début
    printf("\n");
}
```

#### 5. Libération
```c
void cll_free(Node* head) {
    if (!head) return;
    Node* cur = head->next;
    while (cur != head) {
        Node* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    free(head);
}
```

---

## 🔍 Analyse de l'Algorithme

### Différence avec Liste Simple Classique

| Aspect | Simple Linéaire | Circulaire |
|--------|----------------|------------|
| **Dernier nœud** | `->next = NULL` | `->next = head` |
| **Condition d'arrêt** | `cur != NULL` | `cur != start` |
| **Liste à 1 élément** | `head->next = NULL` | `head->next = head` |
| **Détection de fin** | Tester NULL | Comparer avec head |
| **Parcours** | S'arrête | Infini possible |

### Insertion en Tête - Étapes

```
État initial: 
    head -> [5] -> [10] -> [15] ⟲ (retourne à head)

Insérer 2 en tête:

Étape 1: Créer nouveau nœud [2]
Étape 2: Trouver dernier (15)
Étape 3: 15->next = 2
Étape 4: 2->next = 5 (ancien head)
Étape 5: Retourner 2 (nouvelle head)

Résultat:
    head -> [2] -> [5] -> [10] -> [15] ⟲
```

### Insertion en Queue - Étapes

```
État initial:
    head -> [2] -> [5] -> [10] ⟲

Insérer 20 en queue:

Étape 1: Créer nouveau nœud [20]
Étape 2: Trouver dernier (10)
Étape 3: 10->next = 20
Étape 4: 20->next = head (2)
Étape 5: Retourner head inchangé

Résultat:
    head -> [2] -> [5] -> [10] -> [20] ⟲
```

---

## 📊 Visualisation de la Circularité

### Liste Vide
```
head = NULL
```

### Un Seul Élément
```
    ┌─────┐
    │  5  │
    └──┬──┘
       │ next
       └──⟲
```

### Trois Éléments
```
    ┌─────┐     ┌─────┐     ┌─────┐
    │  2  │ --> │  5  │ --> │ 10  │
    └─────┘     └─────┘     └──┬──┘
      ↑                         │
      └─────────────────────────┘
```

### Représentation Circulaire
```
         [2]
        ↗   ↘
    [10]     [5]
      ↖     ↙
        [15]
```

---

## 📊 Analyse de Complexité

### Complexité Temporelle

| Opération | Complexité | Raison |
|-----------|------------|--------|
| **Insert en tête** | O(n) | Doit trouver le dernier nœud |
| **Insert en queue** | O(n) | Doit trouver le dernier nœud |
| **Affichage** | O(n) | Parcours complet |
| **Recherche** | O(n) | Parcours séquentiel |
| **Libération** | O(n) | Libérer tous les nœuds |

### Pourquoi O(n) et pas O(1)?
```
Pour insérer en tête/queue, on doit:
1. Trouver le dernier nœud → O(n)
2. Modifier ses liens → O(1)

Total: O(n) + O(1) = O(n)
```

### Optimisation Possible
```c
// Maintenir un pointeur tail
typedef struct CircularList {
    Node* head;
    Node* tail;  // Pointeur vers le dernier
} CircularList;

// Alors insertion devient O(1) !
```

---

## 🧪 Tests Unitaires

### Test 1: Insertion en Tête
```c
TEST(test_cll_insert_head) {
    Node* cll = cll_create();
    cll = cll_insert_head(cll, 10);
    ASSERT(cll != NULL && cll->data == 10, "CLL insert head");
    cll_free(cll);
}
```
**Résultat**: ✅ PASS

### Test 2: Insertion en Queue
```c
TEST(test_cll_insert_tail) {
    Node* cll = cll_create();
    cll = cll_insert_tail(cll, 10);
    ASSERT(cll != NULL && cll->data == 10, "CLL insert tail");
    cll_free(cll);
}
```
**Résultat**: ✅ PASS

### Test 3: Vérification Circularité (Manuel)
```c
Node* cll = cll_create();
cll = cll_insert_head(cll, 5);
cll = cll_insert_tail(cll, 10);

// Vérifier que le dernier pointe vers head
Node* last = cll;
while (last->next != cll) last = last->next;
assert(last->next == cll);  // ✅ Circulaire
cll_free(cll);
```
**Résultat**: ✅ PASS

### Taux de Réussite
**2/2 tests automatiques + vérifications manuelles (100%)**

---

## 🎬 Exemple d'Exécution Détaillé

### Scénario Complet

**Opérations**: 
1. Insert tête 30
2. Insert queue 40  
3. Insert tête 20
4. Insert queue 50

#### Étape 1: Insert Head 30
```
Liste: [30] ⟲
Vérification: 30->next = 30 ✅
```

#### Étape 2: Insert Tail 40
```
Liste: [30] -> [40] ⟲
Liens:
  30->next = 40
  40->next = 30 ✅
```

#### Étape 3: Insert Head 20
```
Liste: [20] -> [30] -> [40] ⟲
Liens:
  20->next = 30
  30->next = 40
  40->next = 20 ✅
```

#### Étape 4: Insert Tail 50
```
Liste: [20] -> [30] -> [40] -> [50] ⟲
Liens:
  20->next = 30
  30->next = 40
  40->next = 50
  50->next = 20 ✅
```

### Affichage
```
cll_print(cll);
Output: 20 30 40 50
```

### Vérification de Circularité
```c
Node* temp = cll;
int count = 0;
do {
    printf("%d ", temp->data);
    temp = temp->next;
    count++;
} while (temp != cll && count < 10);

// count = 4 (nombre d'éléments)
// temp == cll (retour au début) ✅
```

---

## 🔧 Gestion de la Mémoire

### Cas Particulier: Libération
```c
void cll_free(Node* head) {
    if (!head) return;
    
    // ⚠️ PIÈGE: Ne pas utiliser while (cur != NULL)
    // Car cur ne sera JAMAIS NULL !
    
    Node* cur = head->next;
    while (cur != head) {  // ✅ Comparer avec head
        Node* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    free(head);  // Libérer head à la fin
}
```

### Piège Commun
```c
// ❌ MAUVAIS - Boucle infinie!
Node* cur = head;
while (cur != NULL) {  // Jamais NULL en circulaire!
    free(cur);
    cur = cur->next;
}

// ✅ BON
Node* cur = head->next;
while (cur != head) {
    Node* nxt = cur->next;
    free(cur);
    cur = nxt;
}
free(head);
```

---

## 💡 Avantages de la Circularité

### 1. Accès au Dernier depuis le Premier
```c
// En O(1) si on a un pointeur tail
Node* last = head->prev;  // En liste double circulaire
```

### 2. Parcours Cyclique Naturel
```c
// Utile pour round-robin
Node* current = head;
while (1) {  // Boucle infinie naturelle
    process(current->data);
    current = current->next;
    if (should_stop()) break;
}
```

### 3. Pas de Cas Spécial NULL
```c
// Plus simple: pas besoin de tester NULL partout
// Chaque nœud a TOUJOURS un next valide
```

---

## 📚 Applications Pratiques

### 1. Round-Robin Scheduling
```c
// Système d'exploitation: gestion des processus
typedef struct Process {
    int pid;
    struct Process* next;
} Process;

Process* scheduler_round_robin(Process* current) {
    execute(current);
    return current->next;  // Passe au suivant (circulaire)
}
```

### 2. Jeu Multi-Joueurs
```c
// Tour de jeu circulaire
typedef struct Player {
    char name[50];
    struct Player* next;
} Player;

Player* next_turn(Player* current) {
    return current->next;  // Jamais NULL!
}
```

### 3. Buffer Circulaire
```c
// Producer-Consumer pattern
typedef struct CircularBuffer {
    int data;
    struct CircularBuffer* next;
} CircularBuffer;
```

### 4. Playlist Musicale en Boucle
```c
typedef struct Song {
    char title[100];
    struct Song* next;
} Song;

Song* play_next(Song* current) {
    play(current);
    return current->next;  // Retourne au début automatiquement
}
```

---

## ⚠️ Pièges et Précautions

### Piège 1: Boucle Infinie en Parcours
```c
// ❌ MAUVAIS
Node* cur = head;
while (cur->next != NULL) {  // Jamais NULL!
    cur = cur->next;
}

// ✅ BON
Node* cur = head;
do {
    // traitement
    cur = cur->next;
} while (cur != head);
```

### Piège 2: Liste à Un Élément
```c
// Bien gérer le cas spécial
if (!head) {
    nouveau->next = nouveau;  // Pointe vers lui-même
    return nouveau;
}
```

### Piège 3: Perte de Référence
```c
// ❌ MAUVAIS - Perte de head
head = head->next;  // Impossible de revenir!

// ✅ BON - Sauvegarder
Node* start = head;
Node* cur = head;
do {
    cur = cur->next;
} while (cur != start);
```

---

## 🎓 Concepts Appliqués

### Structures de Données
- Liste circulaire
- Gestion de boucles
- Détection de cycle

### Algorithmes
- Parcours circulaire
- Insertion avec lien circulaire
- Condition d'arrêt non-NULL

### Techniques
- Do-while pour garantir au moins une itération
- Sauvegarde de référence de départ
- Gestion de cas singleton

---

## ✅ Conclusion

L'exercice 4 démontre la **maîtrise des listes circulaires**:

- ✅ Insertion en tête implémentée
- ✅ Insertion en queue implémentée
- ✅ Circularité correctement maintenue
- ✅ Pas de pointeurs NULL (sauf liste vide)
- ✅ Tests validés (2/2)
- ✅ Gestion mémoire sans fuites

### Comparaison avec Liste Simple Linéaire

| Aspect | Linéaire | Circulaire |
|--------|----------|------------|
| **Dernier nœud** | NULL | Vers head |
| **Parcours** | Fini | Potentiellement infini |
| **Détection fin** | `!= NULL` | `!= start` |
| **Applications** | Générales | Round-robin, cycles |

### Points Forts
- Parcours cyclique naturel
- Pas de cas spécial NULL (sauf vide)
- Idéal pour algorithmes circulaires

### Points Faibles
- Insertion O(n) sans optimisation
- Risque de boucle infinie
- Libération plus délicate

### Optimisation Recommandée
```c
// Maintenir pointeur tail pour O(1)
typedef struct {
    Node* head;
    Node* tail;
} CircularList;
```

**Statut Final**: ✅ **VALIDÉ**

---

**Auteur**: HENDRIX MENOUNGA LEGRAND (24G2579)  
**Cours**: INF 231 - Prof. Melatagia  
**Date de Validation**: 1er octobre 2025
