/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:31:03 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/26 11:43:40 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_map(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->rows)
		free(map->grid[row++]);
	free(map->grid);
}

static void	clear_state(t_state *state)
{
	void	**images;

	clear_map(&state->map);
	clear_map(&state->viewport);
	if (state->window)
		mlx_destroy_window(state->mlx, state->window);
	if (state->images)
	{
		images = state->images;
		while (*images)
			mlx_destroy_image(state->mlx, *images++);
		free(state->images);
	}
	if (state->mlx)
	{
		mlx_destroy_display(state->mlx);
		free(state->mlx);
	}
}

static void	exit_game(t_state *state, int exit_value)
{
	clear_state(state);
	exit(exit_value);
}

static void	exit_error(t_state *state, char *msg, int error_value)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit_game(state, error_value);
}

int	main(int argc, char **argv)
{
	t_state	state;
	char	*err;

	ft_bzero(&state, sizeof(state));
	if (argc != 2 || ft_strncmp(".ber", argv[1] + ft_strlen(argv[1]) - 4, 4))
	{
		ft_putendl_fd("Usage: ./so_long <ber_file_name>", 1);
		ft_putendl_fd("(File must be of type .ber and contain a valid map)", 1);
		ft_putendl_fd("See examples in maps/", 1);
		return (0);
	}
	if (map_from_file(&state.map, argv[1]) < 0)
		exit_error(&state, "Failed to open map file.", 1);
	err = map_validate(&state.map);
	if (err)
		exit_error(&state, err, 2);
	state.mlx = mlx_init();
	if (!state.mlx)
		exit_error(&state, "Failed to initialize mlx.", 3);
	err = start_game(&state);
	if (err)
		exit_error(&state, err, 4);
	exit_game(&state, 0);
}
