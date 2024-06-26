CFLAGS = -Wall -Werror -Wextra -g
DEPS = ./include/push_swap.h
NAME = push_swap
RM = rm -rf
CC = gcc
SRC_DIR = ./src/
SRC = $(SRC_DIR)main.c $(SRC_DIR)double_instructions.c $(SRC_DIR)radix_sort.c $(SRC_DIR)little_sort.c $(SRC_DIR)instructions.c $(SRC_DIR)utils.c $(SRC_DIR)init_stack.c
LIBFT_DIR = ./libs/Libft

all: $(NAME)

# -- COLORS -- # 
BLACK=\033[0;30m# Black
RED=\033[0;31m# Red
GREEN=\033[0;32m# GREEN
YELLOW=\033[0;33m# YELLOW	
BLUE=\033[0;34m# BLUE
PURPLE=\033[0;35m# PURPLE
CYAN=\033[0;36m# CYAN
WHITE=\033[0m# WHITE

OBJ = $(SRC:.c=.o)

# génère la bibliothèque en utilisant les fichiers objets. 
$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)Compilation successful. Library: $(NAME) $(WHITE)"

# création des fichiers objets à partir des fichiers source. 
%.o: %.c $(DEPS)
	@$(CC) -c -o $@ $< -I$(LIBFT_DIR) $(CFLAGS)

# supprime les fichiers objets. #
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ)
	@echo "$(CYAN)Object files cleaned successfully. Library: $(NAME) $(WHITE)"
	@echo "--------------------------------------------------------"

# supprime les fichiers objets et la bibliothèque. 
fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(CYAN)Library cleaned successfully. Library: $(NAME) $(WHITE)"
	@echo "--------------------------------------------------------"

re: fclean all

val: all
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap

test:
	@echo "10 tests/ 0 - 500"
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@echo "/	/	/	/	/"
	@echo "10 tests/ 0 - 100"
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@echo "/	/	/	/	/"
	@echo "10 tests/ 0 - 3"
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l

# indique que 'all', 'clean', 'fclean' et 're' ne sont pas des fichiers. #
.PHONY: all clean fclean re