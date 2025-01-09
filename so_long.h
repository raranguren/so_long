/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:31:31 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/09 20:16:42 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <mlx_int.h>
# include <fcntl.h>

# ifndef BER_MAP_MAX_SIZE
#  define BER_MAP_MAX_SIZE 80
# endif

# define WINDOW_TITLE "So long ! (rarangur)"
# define SPRITE_FILE_0 "textures/ugly-0.xpm"
# define SPRITE_FILE_1 "textures/ugly-1.xpm"
# define SPRITE_FILE_P "textures/ugly-p.xpm"
# define SPRITE_FILE_C "textures/ugly-c.xpm"
# define SPRITE_FILE_E "textures/ugly-e.xpm"
# define SPRITE_SIZE 32

typedef struct s_sprites
{
	void	*empty;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_sprites;

typedef struct s_ber_map
{
	char	grid[BER_MAP_MAX_SIZE][BER_MAP_MAX_SIZE];
	int		rows;
	int		cols;
}	t_ber_map;

typedef struct s_game_state
{
	void		*mlx;
	void		*window;
	t_ber_map	map;
	t_sprites	sprites;
	int			ended;
}	t_game_state;

int		map_from_file(t_ber_map *map, char *filename);
int		sprites_from_files(t_game_state *state);
char	*map_validate(t_ber_map *map);
char	*start_game(t_game_state *state);
void	map_display(t_game_state *state, int x, int y);
void	*sprite_to_image(t_game_state *state, char code);
void	move_player(t_game_state *state, int dir_x, int dir_y);

#endif
