NAME = so_long
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX_DIR = libmlx
LIBMLX = $(LIBMLX_DIR)/libmlx.a

CC = gcc
CPPFLAGS = -I $(LIBFT_DIR) -I $(LIBMLX_DIR)
CFLAGS = -Wall -Wextra -Werror -O3
LDLIBS = -L $(LIBFT_DIR) -L $(LIBMLX_DIR) -lft -lmlx -lXext -lX11 -lm

INCLUDES = so_long.h
SRC = so_long.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(OBJ): $(INCLUDES) $(LIBFT) $(LIBMLX) Makefile

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

clean:
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_DIR) clean
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

bonus:
	echo "Not implemented"

debug: $(LIBFT) $(LIBMLX)
	$(CC) $(CPPFLAGS) -Wall -Wextra -g3 $(SRC) -o $(NAME) $(LDLIBS)
