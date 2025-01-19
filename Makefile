NAME = so_long
LIBFT = libft/libft.a

CC = cc
CPPFLAGS = -I libft -I ../minilibx-linux
CFLAGS = -Wall -Wextra -Werror -O3
LDFLAGS = -L libft -L ../minilibx-linux
LDLIBS = -lft -lmlx -lXext -lX11

HEADERS = so_long.h
SRC = \
	map_from_file.c \
	map_validate.c \
	map_has_valid_path.c \
	sprite_to_image.c \
	sprites_from_files.c \
	start_game.c \
	init_viewport_from_screen_size.c \
	refresh_display.c \
	move_player.c \
	so_long.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)

$(OBJ): $(HEADERS) Makefile

$(LIBFT):
	make -C libft all clean --silent

clean:
	make -C libft fclean --silent
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

bonus:

debug: $(LIBFT)
	$(CC) $(CPPFLAGS) -Wall -Wextra -g3 $(LDFLAGS) $(SRC) -o $(NAME) $(LDLIBS)
