NAME = so_long
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CPPFLAGS = -I $(LIBFT_DIR)
CFLAGS = -Wall -Wextra -Werror -O3
LDFLAGS = -L $(LIBFT_DIR)
LDLIBS = -lft -lmlx -lXext -lX11

HEADERS = so_long.h
SRC = \
	map_display.c \
	map_from_file.c \
	map_validate.c \
	map_has_valid_path.c \
	sprite_to_image.c \
	sprites_from_files.c \
	start_game.c \
	move_player.c \
	so_long.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)

$(OBJ): $(HEADERS) $(LIBFT) Makefile

$(LIBFT):
	make -C $(LIBFT_DIR) all clean --silent

clean:
	make -C $(LIBFT_DIR) fclean --silent
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

bonus:

debug: $(LIBFT)
	$(CC) $(CPPFLAGS) -Wall -Wextra -g3 $(LDFLAGS) $(SRC) -o $(NAME) $(LDLIBS)
