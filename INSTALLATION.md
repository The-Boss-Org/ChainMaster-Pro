# 🚀 Installation et Utilisation - ChainMaster Pro

## ✅ Installation Rapide - Windows

### Méthode 1: Double-Clic (Recommandé)
1. **Ouvrez le dossier** `ChainMaster-Pro`
2. **Double-cliquez** sur `build.bat`
3. Attendez la compilation (quelques secondes)
4. ✅ Les exécutables sont dans `build/`

### Méthode 2: Ligne de Commande
```cmd
cd ChainMaster-Pro
build.bat
```

## 📦 Prérequis

### Vérifier GCC
```cmd
gcc --version
```

Si GCC n'est pas installé:
- **Téléchargez TDM-GCC**: https://jmeubank.github.io/tdm-gcc/
- **Ou MinGW-w64**: https://www.mingw-w64.org/
- Ajoutez GCC au PATH Windows

## 🎯 Utilisation

### Lancer le Démo Complet
```cmd
build\demo_all.exe
```
**Affiche**: Démonstration des 5 exercices

### Lancer l'Interface Interactive
```cmd
build\demo.exe
```
**Menu**: Insertion tête/queue pour liste circulaire

### Lancer le Tutorial Guidé
```cmd
build\tutorial.exe
```
**Affiche**: Tutorial pas-à-pas avec explications

### Lancer les Tests
```cmd
build\test_runner.exe
```
**Résultat**: 12 tests - Taux de réussite 100%

## 🔄 Scripts Automatiques

### Pour Démo
```cmd
run_demo.bat
```
Compile automatiquement si nécessaire, puis lance le démo

### Pour Tests
```cmd
run_tests.bat
```
Compile automatiquement si nécessaire, puis lance les tests

## 🧹 Nettoyage

Pour supprimer les fichiers compilés:
```cmd
rmdir /s /q build
```

Puis recompilez avec `build.bat`

## 🐧 Linux/Mac

### Compilation
```bash
make all
```

### Exécution
```bash
# Démo complet
make demo_all

# Tests
make test-all

# Tutorial
make tutorial

# Interface
make demo
```

### Nettoyage
```bash
make clean
```

## 📊 Vérification de l'Installation

Si tout fonctionne, vous devriez voir:

### ✅ Après `build.bat`:
```
========================================
  Compilation reussie!
========================================
```

### ✅ Après `build\test_runner.exe`:
```
Tests Passed: 12
Tests Failed: 0
Success Rate: 100.0%
```

### ✅ Après `build\demo_all.exe`:
```
SLL triée: 1 3 3 3 5 7 9
SLL après suppression de 3: 1 5 7 9
DLL triée: 2 4 6 8 10
CLL: 1 2 4 5
CDLL avant: 10 20 30 40
CDLL arrière: 40 30 20 10
```

## 🆘 Dépannage

### Erreur: "gcc n'est pas reconnu"
- Installez GCC (voir Prérequis)
- Ajoutez GCC au PATH

### Erreur de compilation
```cmd
# Nettoyez et recompilez
rmdir /s /q build
build.bat
```

### Les .exe ne se lancent pas
- Vérifiez l'antivirus (peut bloquer)
- Lancez en administrateur si nécessaire

## 📚 Documentation

Après installation, consultez:
- `QUICKSTART.md` - Démarrage rapide
- `docs/GUIDE_UTILISATION.md` - Guide complet
- `docs/THEORIE_LISTES.md` - Théorie
- `docs/API_REFERENCE.md` - Référence API

## ✨ Fonctionnalités

Le projet ChainMaster Pro inclut:
- ✅ 5 exercices complets en C
- ✅ 12 tests unitaires
- ✅ 4 programmes exécutables
- ✅ Documentation complète (2000+ lignes)
- ✅ Exemples pratiques

## 🎓 Support Académique

Pour le cours **INF 231** - Prof. Melatagia
- Tous les exercices du 25 septembre 2025 sont implémentés
- Code commenté et documenté en français
- Tests validant chaque fonctionnalité

---

**Installation réussie! Bon apprentissage! 🚀**
