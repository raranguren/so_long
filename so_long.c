/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:31:03 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/08 23:56:23 by rarangur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game_state *state, int return_value)
{
	if (state->window)
		mlx_destroy_window(state->mlx, state->window);
	if (state->mlx)
	{
		mlx_destroy_display(state->mlx);
		free(state->mlx);
	}
	exit(return_value);
}

void	exit_error(t_game_state *state, char *msg, int error_value)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit_game(state, error_value);
}

int	main(int argc, char **argv)
{
	t_game_state	state;
	char			*err;

	ft_bzero(&state, sizeof(state));
	if (argc != 2)
		return (ft_printf("Usage: ./so_long <ber_file_name>\n"), 0);
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
		exit_error(&state, err, 3);
	exit_game(&state, 0);
}
