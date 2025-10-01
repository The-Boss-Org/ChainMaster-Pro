# 🎯 ChainMaster Pro - Maîtrise des Listes Chaînées en C

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_library))
[![Status: Active](https://img.shields.io/badge/Status-Active-brightgreen.svg)](https://github.com/your-repo)
[![Build: Passing](https://img.shields.io/badge/Build-Passing-success.svg)](https://github.com/your-repo)

## 📖 Présentation du Projet

**ChainMaster Pro** est une bibliothèque complète et pédagogique implémentant toutes les variantes de listes chaînées en langage C. Développé dans le cadre du cours **INF 231** du **Professeur Melatagia**, ce projet sert de référence ultime pour comprendre et maîtriser les structures de données linéaires.

> 🎓 **Projet Académique** - Université de Yaoundé 1 - 2025

## 👥 Équipe de Développement

| Matricule | Membre | Tâche Assignée | Statut |
|------|--------|----------------|---------|
| 23V2294 | MATAGNE DASSE PRESLIE CHANEL | Exercice 5 - Listes doublement circulaires | ✅ Complété |
| 24G2771 | OUMAROU MVONGO CALEB ISRAEL | Exercice 1 - Suppression avancée | ✅ Complété |
| 24F2658 | VAMI NEGUEM YVO FREED | Exercice 2 - Insertion triée simple | ✅ Complété |
| 24G2255 | FOKOU FOFOU STEDDY RONEL | Exercice 3 - Insertion triée double | ✅ Complété |
| 24G2579 | HENDRIX MENOUNGA LEGRAND | Exercice 4 - Listes circulaires simples | ✅ Complété |

## 🚀 Fonctionnalités Principales

### 🔥 Modules Implémentés

| Module | Complexité | Features | Statut |
|--------|------------|----------|---------|
| **Suppression Intelligente** | O(n) | Suppression multi-occurrences, gestion mémoire | ✅ |
| **Insertion Triée Simple** | O(n) | Maintien ordre croissant, optimisation | ✅ |
| **Insertion Triée Double** | O(n) | Navigation bidirectionnelle, cohérence | ✅ |
| **Circularité Simple** | O(1) | Insertion tête/queue rapide, gestion fine | ✅ |
| **Circularité Double** ✅ | **O(1)** | **Double liaison, circularité parfaite** | ✅ |

### 🎯 Highlights Techniques

- **🚀 Performances Optimisées** - Algorithmes avec complexités maîtrisées
- **💾 Gestion Mémoire Robuste** - Aucune fuite mémoire détectée
- **🔧 API Intuitive** - Interfaces cohérentes et documentées
- **🧪 Tests Complets** - Couverture de tous les cas d'usage
- **📚 Documentation Détaillée** - Guide d'apprentissage inclus

## 🏗️ Architecture du Projet

```bash
ChainMaster-Pro/
├── 📂 src/
│ ├── core/
│ │ ├── list_simple.c # Exercice 1 & 2
│ │ ├── list_double.c # Exercice 3
│ │ ├── list_circulaire_simple.c # Exercice 4
│ │ ├── list_circulaire_double.c # Exercice 5
│ │ ├── common.c # Utilitaires communs
│ │ └── interface/
│ │     └── main.c # Programme démonstration interactive
│ └── tests/
│     └── test_runner.c # Suite de tests unitaires
├── 📂 include/
│ ├── chainmaster.h # Header principal
│ ├── structures.h # Définitions structures
│ └── interfaces.h # Prototypes fonctions
├── 📂 docs/
│ ├── GUIDE_UTILISATION.md
│ ├── THEORIE_LISTES.md
│ └── API_REFERENCE.md
├── 📂 examples/
│ ├── demo_complete.c
│ └── tutorial.c
├── 📂 rapports/
│ ├── README.md # Index des rapports
│ ├── RAPPORT_EXERCICE_1.md # Suppression occurrences
│ ├── RAPPORT_EXERCICE_2.md # Insertion triée simple
│ ├── RAPPORT_EXERCICE_3.md # Insertion triée double
│ ├── RAPPORT_EXERCICE_4.md # Liste circulaire simple
│ └── RAPPORT_EXERCICE_5.md # Liste circulaire double
├── Makefile
├── LICENSE
└── README.md
```

## ⚡ Démarrage Rapide

### 🪟 Windows (Double-Clic)
```cmd
# 1. Double-cliquez sur: build.bat
# 2. Lancez le démo:
build\demo_all.exe

# Ou utilisez les scripts automatiques:
run_demo.bat     # Compile et lance le démo
run_tests.bat    # Compile et lance les tests
```

### 🐧 Linux/Mac
```bash
# Compilation complète
make all

# Lancement des démos
make demo_all

# Tests
make test-all
```

### Prérequis
- **Compilateur C**: GCC (MinGW/TDM-GCC pour Windows)
- **Make** (optionnel sur Windows, utilisez build.bat)
- **Git** (pour cloner le projet)
Utilisation Basique
c
#include "chainmaster.h"

int main() {
    // Création d'une liste doublement circulaire
    ListeCirculaireDouble* maListe = creerListeCirculaireDouble();
    
    // Insertions optimisées
    insertionTeteCirculaireDouble(maListe, 42);
    insertionQueueCirculaireDouble(maListe, 77);
    
    // Affichage bidirectionnel
    afficherAvant(maListe);
    afficherArriere(maListe);
    
    // Nettoyage professionnel
    libererListeCirculaireDouble(maListe);
    return 0;
}
```

# 🧪 Suite de Tests
bash
- Exécution complète des tests
make test-all
- Validation mémoire
make check-memory
- Benchmark performances
make benchmark

# Standards de Code
✅ French/English naming convention

✅ Commentaires détaillés pour les algorithmes complexes

✅ Gestion d'erreurs exhaustive

✅ Tests unitaires obligatoires

✅ Documentation API à jour

# Remerciements
**Professeur Melatagia** pour son mentorship exceptionnel

🎓 Projet Académique - INF 231 - Structures de Données

📅 Année 2025 - Université de Yaoundé 1

👨‍💻 Leader MATAGNE DASSE Preslie Chanel


★ ChainMaster Pro - La référence ultime des listes chaînées en C ★
