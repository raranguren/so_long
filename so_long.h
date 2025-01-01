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
	t_ber_map	*map;
}	t_game_state;

t_ber_map	*new_map_from_file(char *filename);

#endif
