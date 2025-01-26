NAME = so_long
NAME_BONUS = so_long_bonus
LIBFT = libft/libft.a

CC = cc
CPPFLAGS = -I. -Ilibft -I../minilibx-linux
CFLAGS = -Wall -Wextra -Werror -O3
LDFLAGS = -Llibft -L../minilibx-linux
LDLIBS = -lft -lmlx -lXext -lX11

HEADERS = so_long.h
HEADERS_BONUS = so_long_bonus.h
SRC = \
	src/map_from_file.c \
	src/map_validate.c \
	src/map_has_valid_path.c \
	src/init_viewport.c \
	src/refresh_display.c \
	src/sprite_to_image.c \
	src/sprites_from_files.c \
	src/start_game.c \
	src/move_player.c
SRC_BONUS = \
	src/map_from_file.c \
	src/map_validate.c \
	src/map_has_valid_path.c \
	src/init_viewport.c \
	src/refresh_display.c \
	src_bonus/sprite_to_image_bonus.c \
	src_bonus/sprites_from_files_bonus.c \
	src_bonus/start_game_bonus.c \
	src_bonus/move_player_bonus.c \
	src_bonus/move_patrols_bonus.c \
	src_bonus/init_patrols_bonus.c \
	so_long.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)
bonus: $(NAME_BONUS)
$(NAME): $(OBJ) $(LIBFT)
$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
$(OBJ): $(HEADERS) Makefile
$(OBJ_BONUS): $(HEADERS_BONUS) Makefile

$(LIBFT):
	make -C libft all clean --silent

clean:
	make -C libft fclean --silent
	rm -fr $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -fr $(NAME) $(NAME_BONUS)

re: fclean all
