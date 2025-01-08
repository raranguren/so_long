/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarangur <rarangur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:31:03 by rarangur          #+#    #+#             */
/*   Updated: 2025/01/08 17:19:55 by rarangur         ###   ########.fr       */
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

int	destroy_window_hook(t_game_state *state)
{
	exit_game((t_game_state *)state, 0);
	return (0);
}

int	expose_hook(t_game_state *state)
{
	(void)state;
	return ft_printf("expose_hook\n");
}

void	test_image(t_game_state *state)
{
	void	*img;
	int		size;

	size = 32;
	img = mlx_xpm_file_to_image(state->mlx, \
			"textures/ugly-0.xpm", &size, &size);
	mlx_put_image_to_window(state->mlx, state->window, img, 10, 10);
	mlx_destroy_image(state->mlx, img);
}

int	key_hook(int keycode, t_game_state *state)
{
	if (keycode == XK_Escape)
		exit_game(state, 0);
	if (keycode == XK_q)
		test_image(state);
	else
		ft_printf("key_hook %x\nptr %p\n", keycode, state->mlx);
	return (0);
}

int	loop_hook(void *state)
{
	(void)state;
	return ft_printf("loop_hook\n");
}

int	main(int argc, char **argv)
{
	t_game_state	state;

	ft_bzero(&state, sizeof(state));
	if (argc != 2)
		return (ft_printf("Usage: ./so_long <ber_file_name>\n"), 0);
	if (fill_map_from_file(&state.map, argv[1]) < 0)
		exit_error(&state, "Failed to open map file.", 1);
	if (map_validation_error(&state.map))
		exit_error(&state, map_validation_error(&state.map), 2);
	if (!(state.mlx = mlx_init()))
		exit_error(&state, "Failed to initialize mlx.", 3);
	state.window = mlx_new_window(state.mlx, 200, 200, "So Long (rarangur)");
	if (!state.window)
		exit_error(&state, "Failed to open a window.", 3);
	mlx_key_hook(state.window, key_hook, &state);
	mlx_expose_hook(state.window, expose_hook, &state);
	mlx_loop_hook(state.window, loop_hook, &state);
	mlx_hook(state.window, DestroyNotify, None, destroy_window_hook, &state);
	mlx_loop(state.mlx);
}
