# Groupe 11 - TP Programmation en C

# Système de Gestion des Étudiants

## Table des Matières

- [Description](#-description)
- [Fonctionnalités](#-fonctionnalités)
- [Architecture du Projet](#-architecture-du-projet)
- [Installation](#-installation)

## Description

Application console en C pour la gestion complète des données étudiantes. Ce système permet d'enregistrer, modifier, rechercher, supprimer et organiser les informations des étudiants de manière efficace et professionnelle.

### Données Gérées

- **Matricule** : Identifiant unique de l'étudiant
- **Nom** : Nom de famille
- **Prénom** : Prénom de l'étudiant
- **Date de naissance** : Format JJ/MM/AAAA
- **Sexe** : M (Masculin) / F (Féminin)
- **Département** : Département d'études
- **Filière** : Option/Spécialisation
- **Région d'origine** : Région de provenance

## Fonctionnalités

### Menu Principal

1. **Enregistrer** - Ajouter un nouvel étudiant
2. **Modifier** - Mettre à jour les informations d'un étudiant existant
3. **Rechercher (Matricule)** - Recherche linéaire par matricule
4. **Supprimer** - Retirer un étudiant de la base
5. **Trier par ordre alphabétique** - Tri croissant par nom
6. **Recherche dichotomique** - Recherche binaire optimisée (liste triée requise)
7. **Calculer l'âge** - Calcul automatique de l'âge à partir de la date de naissance
8. **Trier par filière** - Organisation par filière d'études
9. **Afficher la liste** - Vue d'ensemble formatée de tous les étudiants

## Architecture du Projet

```
Student-Management-System/
│
├── src/                          # Code source
│   ├── main.c                    
│   ├── student.c                
│   ├── menu.c                   
│   ├── operations.c             
│   ├── search.c                 
│   ├── sort.c                   
│   ├── utils.c                  
│   ├── data.c                   
│   └── validation.c             
│
├── include/                      # fichiers d'entête
│   ├── student.h                
│   ├── menu.h                   
│   ├── operations.h             
│   ├── search.h                 
│   ├── sort.h                   
│   ├── utils.h 
│   ├── data.h                  
│   ├── validation.h             
│   └── config.h 
│
├── data/                         # Données persistantes
│   └── students.dat             
│
├── .gitignore  
└── README.md 
```

## Installation

### Prérequis

- Compilateur GCC (MinGW pour Windows)
- Git

### Compilation

```bash
# Cloner le dépôt
git clone https://github.com/zzAdji/Student-Management-System.git
cd Student-Management-System

# Compiler
gcc src/*.c -Iinclude -o sms

# Exécuter
./sms
```

**Dernière mise à jour** : 25 Janvier 2026
