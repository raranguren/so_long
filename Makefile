NAME = so_long
NAME_BONUS = so_long_bonus
LIBFT = libft/libft.a

CC = cc
CPPFLAGS = -I include -I libft -I ../minilibx-linux
CFLAGS = -Wall -Wextra -Werror -O3
LDFLAGS = -L libft -L ../minilibx-linux
LDLIBS = -lft -lmlx -lXext -lX11

HEADERS = include/so_long.h
SRC = \
	src/map_from_file.c \
	src/map_validate.c \
	src/map_has_valid_path.c \
	src/sprite_to_image.c \
	src/sprites_from_files.c \
	src/start_game.c \
	src/init_viewport_from_screen_size.c \
	src/refresh_display.c \
	src/move_player.c \
	src/so_long.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(LDFLAGS) $(OBJ) -o $(NAME) $(LDLIBS)

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
