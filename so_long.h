/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:31:31 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/19 13:02:42 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <mlx.h>
# include <mlx_int.h>
# include <fcntl.h>

# define WINDOW_TITLE "So long ! (rarangur)"
# define SPRITE_FILE_0 "textures/deep_0.xpm"
# define SPRITE_FILE_1 "textures/deep_1.xpm"
# define SPRITE_FILE_P "textures/deep_p.xpm"
# define SPRITE_FILE_C "textures/deep_c.xpm"
# define SPRITE_FILE_E "textures/deep_e.xpm"
# define SPRITE_SIZE 42
# define WINDOW_SIZE_PERCENT 50
# define SCROLL_TRIGGER_PERCENT 30

typedef struct s_sprites
{
	void	*empty;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_sprites;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
}	t_map;

typedef struct s_state
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_map		viewport;
	int			scroll_x;
	int			scroll_y;
	t_sprites	sprites;
	int			moves;
	int			ended;
}	t_state;

int		map_from_file(t_map *map, char *filename);
int		sprites_from_files(t_state *state);
char	*map_validate(t_map *map);
int		map_has_valid_path(t_map *map);
char	*start_game(t_state *state);
int		init_viewport_for_screen_size(t_state *state);
void	refresh_display(t_state *state);
void	*sprite_to_image(t_state *state, char code);
void	move_player(t_state *state, int dir_x, int dir_y);

#endif
