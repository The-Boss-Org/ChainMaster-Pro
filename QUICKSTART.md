# ⚡ Démarrage Rapide - ChainMaster Pro

## 🎯 En 3 Minutes

### Windows (Recommandé)

1. **Double-cliquez sur `build.bat`**
   - Compile automatiquement tous les programmes
   - Crée le dossier `build/`

2. **Lancez le démo**
   ```cmd
   build\demo_all.exe
   ```

3. **Lancez les tests**
   ```cmd
   build\test_runner.exe
   ```

### Alternative: Scripts Automatiques

- **`run_demo.bat`** - Compile et lance le démo complet
- **`run_tests.bat`** - Compile et lance les tests

### Linux/Mac

```bash
# Compilation
make all

# Lancer le démo complet
make demo_all

# Lancer les tests
make test-all

# Lancer le tutorial
make tutorial
```

## 📚 Les 5 Exercices

### Exercice 1: Suppression de toutes les occurrences
```c
SNode* list = sll_insert_sorted(NULL, 3);
list = sll_delete_all(list, 3);  // Supprime tous les 3
```

### Exercice 2: Insertion triée (liste simple)
```c
SNode* list = NULL;
list = sll_insert_sorted(list, 5);
list = sll_insert_sorted(list, 2);  // Maintient l'ordre
```

### Exercice 3: Insertion triée (liste double)
```c
DList* list = NULL;
list = dll_insert_sorted(list, 10);
list = dll_insert_sorted(list, 5);
```

### Exercice 4: Liste circulaire simple
```c
Node* cll = cll_create();
cll = cll_insert_head(cll, 10);
cll = cll_insert_tail(cll, 20);
cll_print(cll);
cll_free(cll);
```

### Exercice 5: Liste circulaire double
```c
DNode* cdll = cdll_create();
cdll = cdll_insert_head(cdll, 10);  // O(1)
cdll = cdll_insert_tail(cdll, 20);  // O(1)
cdll_print_forward(cdll);
cdll_free(cdll);
```

## 🔧 Compilation Manuelle

Si vous voulez compiler à la main:

```cmd
gcc -Iinclude -Wall -Wextra -O2 src/core/*.c examples/demo_complete.c -o demo.exe
```

## 📖 Documentation Complète

- **GUIDE_UTILISATION.md** - Guide détaillé
- **THEORIE_LISTES.md** - Concepts théoriques
- **API_REFERENCE.md** - Référence des fonctions

## 🆘 Problèmes?

### GCC non trouvé
**Installez MinGW ou TDM-GCC:**
- Téléchargez: https://jmeubank.github.io/tdm-gcc/
- Ajoutez au PATH Windows

### Erreurs de compilation
```cmd
# Nettoyez et recompilez
rmdir /s /q build
build.bat
```

## ✅ Vérification Rapide

Tout fonctionne si:
- `build.bat` termine sans erreur
- `build\demo_all.exe` s'exécute et affiche les résultats
- `build\test_runner.exe` montre "Tests Passed"

---

**Vous êtes prêt! Bon apprentissage! 🚀**
