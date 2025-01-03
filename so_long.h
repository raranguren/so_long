/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:31:31 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/03 17:31:37 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define KEY_ESC 65307


# ifndef BER_MAP_MAX_SIZE
#  define BER_MAP_MAX_SIZE 80
# endif

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
}	t_game_state;

int		fill_map_from_file(t_ber_map *map, char *filename);
char	*map_validation_error(t_ber_map *map);

#endif
