# Makefile pour Système de Gestion des Étudiants
# Auteurs: Équipe de développement
# Date: Décembre 2024

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -std=c11
LDFLAGS = -lm

# Répertoires
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN_DIR = bin
DATA_DIR = data

# Nom de l'exécutable
TARGET = $(BIN_DIR)/sms

# Fichiers sources et objets
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
HEADERS = $(wildcard $(INC_DIR)/*.h)

# Couleurs pour output (optionnel)
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m # No Color

# Règle par défaut
all: directories $(TARGET)
	@echo "$(GREEN)✓ Compilation réussie!$(NC)"
	@echo "$(YELLOW)Exécutez: ./$(TARGET)$(NC)"

# Créer les répertoires nécessaires
directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(DATA_DIR)

# Règle pour créer l'exécutable
$(TARGET): $(OBJECTS)
	@echo "$(YELLOW)Linking...$(NC)"
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Règle pour compiler les fichiers .c en .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers compilés
clean:
	@echo "$(YELLOW)Nettoyage des fichiers objets...$(NC)"
	rm -rf $(BUILD_DIR)/*.o
	@echo "$(GREEN)✓ Nettoyage terminé$(NC)"

# Nettoyer complètement (incluant l'exécutable)
fclean: clean
	@echo "$(YELLOW)Suppression de l'exécutable...$(NC)"
	rm -rf $(BIN_DIR)/*
	@echo "$(GREEN)✓ Nettoyage complet terminé$(NC)"

# Recompiler depuis zéro
re: fclean all

# Exécuter le programme
run: all
	@echo "$(GREEN)Lancement du programme...$(NC)"
	./$(TARGET)

# Compilation avec mode debug
debug: CFLAGS += -g -DDEBUG
debug: all
	@echo "$(GREEN)✓ Compilation en mode debug$(NC)"

# Vérifier la syntaxe sans compiler
check:
	@echo "$(YELLOW)Vérification de la syntaxe...$(NC)"
	$(CC) $(CFLAGS) -fsyntax-only $(SOURCES)
	@echo "$(GREEN)✓ Aucune erreur de syntaxe$(NC)"

# Afficher les warnings détaillés
warnings: CFLAGS += -pedantic
warnings: all

# Créer une archive du projet
archive:
	@echo "$(YELLOW)Création de l'archive...$(NC)"
	tar -czf sms_$(shell date +%Y%m%d_%H%M%S).tar.gz \
		$(SRC_DIR) $(INC_DIR) Makefile README.md
	@echo "$(GREEN)✓ Archive créée$(NC)"

# Afficher l'aide
help:
	@echo "$(GREEN)Makefile - Système de Gestion des Étudiants$(NC)"
	@echo ""
	@echo "Commandes disponibles:"
	@echo "  $(YELLOW)make$(NC) ou $(YELLOW)make all$(NC)      - Compiler le projet"
	@echo "  $(YELLOW)make run$(NC)              - Compiler et exécuter"
	@echo "  $(YELLOW)make clean$(NC)            - Supprimer les fichiers objets"
	@echo "  $(YELLOW)make fclean$(NC)           - Nettoyage complet"
	@echo "  $(YELLOW)make re$(NC)               - Recompiler depuis zéro"
	@echo "  $(YELLOW)make debug$(NC)            - Compiler en mode debug"
	@echo "  $(YELLOW)make check$(NC)            - Vérifier la syntaxe"
	@echo "  $(YELLOW)make warnings$(NC)         - Compilation avec warnings détaillés"
	@echo "  $(YELLOW)make archive$(NC)          - Créer une archive du projet"
	@echo "  $(YELLOW)make help$(NC)             - Afficher cette aide"
	@echo ""

# Empêcher make d'interpréter les noms de fichiers
.PHONY: all clean fclean re run debug check warnings archive help directories

# Afficher les variables (pour debug du Makefile)
print-%:
	@echo $* = $($*)