NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra 

LIBFT_DIR = src/libft/
LIBFT_FILES = libft.a
LIBFT_INCLUDES = $(LIBFT_DIR)includes/
LIBFT = $(LIBFT_DIR)$(LIBFT_FILES)

PARSING_DIR := src/parsing/
PARSING_FILES := ft_atoi_err.c \
				parsing.c \

FILES_INCLUDES := includes/
C_FILES := $(NAME).c \
		   $(addprefix $(PARSING_DIR), $(PARSING_FILES))

OBJ_DIR := .obj/
OBJ_FILES := $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))
DEP_FILES := $(OBJ_FILES:.o=.d)

.PHONY: all clean fclean re exec

all: git makelibft $(NAME)

makelibft:
	$(MAKE) -C src/libft/

git:
	git submodule update --init --remote --recursive

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -I $(FILES_INCLUDES) -I $(LIBFT_INCLUDES) $^ $(LIBFT) -o $@ 

-include $(DEP_FILES)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)$(PARSING_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c -I $(FILES_INCLUDES) -I $(LIBFT_INCLUDES) $< -o $@

$(OBJ_DIR)$(PARSING_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C src/libft clean
	rm -f $(OBJ_FILES)
	rm -f $(DEP_FILES)

fclean:
	$(MAKE) -C src/libft fclean
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

exec: 
	./$(NAME) 50 50
